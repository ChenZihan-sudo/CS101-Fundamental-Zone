'use strict';

define(['jquery', 'h5/videoModel', 'h5/videoCtrl', 'h5/h5StatApi', 'h5/h5EventApi', 'h5/md5'], function ($, videoModel, videoCtrl, stats, vEvents, md5) {
    var h5timing = {
        _videoRefID: '', _studyID: '', _userID: '', _courseID: '', _duration: 0, _playSpeed: 1.0, _playTime: 0, _getSysTimeUrl: '', _openTime: null, _time: null, _postTimeKey: null, _timingState: null, _timePointCache: 0, _item: { pointStart: null, pointEnd: null, speed: 1.0, timeStart: null, timeEnd: null }, _items: [], _traceInfo: { refType: 'video', source: 'pch5hls', rangeStart: '0', rangeEnd: '', items: null }, _postDataUrl: '', _basePath: '', _st: 1000 * 60 * 3, setPostTimeOut: function (callback, delay) {
            var setTimeoutId, start, remaining = delay;
            this.pause = function () {
                window.clearTimeout(setTimeoutId);
                remaining -= new Date() - start;
                h5timing._timingState = "pause"
            };
            this.play = function () {
                start = new Date();
                window.clearTimeout(setTimeoutId);
                setTimeoutId = window.setTimeout(callback, remaining);
                h5timing._timingState = "play"
            };
            this.play()
        }, initVideoRefID: function () {
            this._videoRefID = videoModel.getVideoInfo().videoRefID;
            this._userID = videoModel.getPlayStatus().userID;
            this._studyID = videoModel.getVideoInfo().studyID;
            this._courseID = videoModel.getVideoInfo().courseID
        }, initPlaySpeed: function () { this._playSpeed = videoModel.getPlayStatus().playSpeed }, initDuration: function () {
            this._duration = stats.getDuration();
            if (!this._duration) {
                var _this = this;
                setTimeout(function () { _this.initDuration.call(_this) }, 100)
            } this._traceInfo.rangeEnd = this._duration + ''
        }, initOpenTime: function () {
            this._time = parseInt(videoModel.getPlayerOpts().serverTime);
            this._openTime = parseInt(videoModel.getPlayerOpts().serverTime)
        }, initInterfaceUrl: function () {
            h5timing._basePath = videoModel.getInterfaces().BASE_PATH;
            h5timing._postDataUrl = videoModel.getInterfaces().POST_TIMING_DATA_URL;
            h5timing._getSysTimeUrl = videoModel.getInterfaces().getServerTimeUrl;
            h5timing._postTimeKey = videoModel.getPlayerOpts().postTimeKey;
            if (!h5timing._getSysTimeUrl) { setTimeout(h5timing.initInterfaceUrl, 100) }
        }, getPostInterval: function () { return videoModel.getPlayerOpts().postInterval }, getSysTime: function (url, callback) {
            var _this = this;
            $.ajax({
                url: url, type: 'post', success: function (result) {
                    h5timing._openTime = parseInt(result);
                    h5timing._time = parseInt(result);
                    callback && callback()
                }
            })
        }, start: function () { if (videoModel.getPlayerOpts().isSaveTime !== 1) { return } this.init() }, init: function () {
            this.initInterfaceUrl();
            this.initOpenTime();
            setTimeout(this.timeInterval, 1000);
            this._initData();
            this._initEvents();
            this._initPostEvents()
        }, _initData: function () {
            this.initVideoRefID();
            this.initPlaySpeed();
            this.initDuration()
        }, _initEvents: function () {
            var _th = this;
            if (stats.getMediaStatus() === 'play') { _th.itemStart() } vEvents.sub('media.playing', function () { window.setTimeout(function () { _th.itemStart() }, 1000) });
            vEvents.sub('media.waiting', function (currentTime) { _th.itemEnd(currentTime) });
            vEvents.sub('media.pause', function (currentTime) { _th.itemEnd(currentTime) });
            vEvents.sub('media.ended', function (currentTime) { _th.itemEnd(currentTime) });
            vEvents.sub('media.ratechange', function (speed) {
                _th.itemEnd();
                _th._playSpeed = speed;
                _th.itemStart()
            })
        }, _initPostEvents: function () {
            var _th = this;
            _th._st = this.getPostInterval();
            this.setPostTimeOut(_th.saveInterval, _th._st);
            $(window).on('beforeunload unload', (function () {
                var isAsync = false;
                var userAgent = navigator.userAgent;
                if (userAgent.indexOf('Chrome') != -1) {
                    try {
                        var verStr = userAgent.match(/Chrome\/([\d.]+)/)[1];
                        var verNum = Number(verStr.split(".")[0]);
                        if (verNum >= 79) { isAsync = true }
                    } catch (err) { isAsync = false }
                } var invokeFlag = false;
                return function () {
                    if (ningBoRefreshPageIsPost != undefined && ningBoRefreshPageIsPost) {
                        console.log("关闭、刷新页面时提交计时数据:");
                        !invokeFlag && _th.saveData(isAsync, true)
                    }
                }
            })());
            vEvents.sub('media.mediachange', function (videoRefID) {
                _th._videoRefID = videoRefID;
                _th.initDuration();
                _th.itemStart()
            });
            vEvents.sub('inner.autoNext', function (videoRefID) { _th._playTime = stats.getCurrentTime() });
            vEvents.sub('ui.preMedia ui.nextMedia', function (id) {
                _th.saveData(true, true);
                _th._playTime = stats.getCurrentTime()
            });
            vEvents.sub('media.ended', function (duration, hasNext) { _th.saveData(true, false, 1) })
        },
        itemStart: function () {
            if (h5timing._timingState == 'pause') { h5timing.play() } this._item || (this._item = {});
            if (this._item.pointStart) { return } this._item.pointStart = stats.getCurrentTime();
            this._item.timeStart = this.getTime();
            this._item.speed = this._playSpeed
        },
        itemEnd: function (pointEnd) {
            if (h5timing._timingState == 'play') { h5timing.pause() } if (!this._item) { return } this._item.timeEnd = this.getTime();
            this._item.pointEnd = pointEnd ? pointEnd : stats.getCurrentTime();
            if (this._item.pointStart < this._item.pointEnd) { this._items.push(this._item) } this._item = null
        },
        timeInterval: function () {
            h5timing._time += 1000;
            setTimeout(h5timing.timeInterval, 1000)
        },
        saveInterval: function () {
            h5timing.setPostTimeOut(h5timing.saveInterval, h5timing._st);
            h5timing.saveData(true, true)
        },
        saveData: function (isAsync, isTimeCheck, isEnded) {
            if (isEnded == undefined) { isEnded = 0 } var _this = this;
            if (!_this._duration) { return false } if (_this._userID == 0) { return false } _this.itemEnd();
            if (stats.getMediaStatus() === 'play') { h5timing.itemStart() } else { h5timing.pause() } if (_this._items.length < 1) return false;
            var items = _this.clone(_this._items);
            _this._items = [];
            var traceInfo = _this.clone(_this._traceInfo);
            traceInfo.items = items;
            var basePath = _this._basePath;
            var postDataUrl = _this._postDataUrl;
            var playTime = stats.getCurrentTime();
            if (playTime == 0) {
                playTime = _this._playTime;
                _this._playTime = 0
            } var sysTimeUrl = h5timing._basePath + h5timing._getSysTimeUrl;
            var innerTime = 0;
            for (var j = 0, len = traceInfo.items.length;
                j < len;
                j++) { if (traceInfo.items[j].pointStart != null) { innerTime += traceInfo.items[j].pointEnd - traceInfo.items[j].pointStart } } if (isTimeCheck && (!_this.getTime() || (_this.getTime() - _this._openTime) < 8 * 1000)) { return false } if (innerTime > (60 * 5)) { innerTime = 300 } var videoID = _this._videoRefID;
            this.getSysTime(sysTimeUrl, function () {
                var hs = h5timing._openTime;
                var postTimeKey = h5timing._postTimeKey;
                var keyStr = videoID.toString() + playTime.toString() + innerTime.toString() + postTimeKey + hs;
                var keyMd5Str = hex_md5(keyStr);
                $.ajax({
                    url: basePath + postDataUrl, dataType: 'json', async: isAsync, type: 'post', data: { videoID: videoID, studyID: _this._studyID, userID: _this._userID, courseID: _this._courseID, key: keyMd5Str, hs: hs, playTime: playTime, innerTime: innerTime, isEnded: isEnded }, success: function (result) {
                        if (result.retCode == '2') {
                            videoCtrl.pause();
                            h5timing.pause();
                            document.getElementById("videoPointBg").style.display = "block";
                            new Popup({
                                width: 300, height: 220, autoScroll: true, type: "error", title: '系统提示', subBtnType: 'custom', btnContent: [], tanContent: result.retMsg, _Events: function () {
                                    var item = this;
                                    $(".sure").on('click', function () {
                                        item._close(item);
                                        flashApi.playVideo()
                                    });
                                    $(".popClose").on('click', function () {
                                        item._close(item);
                                        flashApi.playVideo()
                                    })
                                }
                            })
                        } if (result.retCode == '3') {
                            videoCtrl.pause();
                            h5timing.pause();
                            alert(result.retMsg);
                            location.href = '/sys/logOut'
                        }
                    }, error: function (result) { alert(result.retMsg) }
                })
            })
        }, getTime: function () {
            if (this._time) return this._time;
            else return null
        }, clone: function (obj) {
            var str, newobj = obj.constructor === Array ? [] : {};
            if (typeof obj !== 'object') { return } else if (window.JSON) {
                str = JSON.stringify(obj);
                newobj = JSON.parse(str)
            } else { for (var i in obj) { newobj[i] = typeof obj[i] === 'object' ? this.clone(obj[i]) : obj[i] } } return newobj
        }
    };
    h5timing.start();
    return h5timing
});
