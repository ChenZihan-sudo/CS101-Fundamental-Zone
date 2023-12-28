

function execute() {

    // if (document.getElementById("videoPoint").style.cssText.search('none')) return;

    if (document.getElementsByClassName("ctit") && document.getElementsByClassName("cbtn")[0]) {
        console.log("_________________________");
        document.getElementById("closePointId").childNodes[1].click()
        console.log("显示答案");
        if (document.getElementsByClassName("ctit")[0].innerHTML.search("多选题") >= 0 || document.getElementsByClassName("ctit")[0].innerHTML.search("单选题") >= 0) {
            console.log("单选或多选题");

            var answerOrigin = document.getElementById("PointQuestionAnswer0").childNodes[0].childNodes[0].data

            var dict = ['A', 'B', 'C', 'D']
            var stor = [];

            for (var i = 0; i < answerOrigin.length; i++) {
                for (var j = 0; j < dict.length; j++) {
                    if (answerOrigin[i] == dict[j]) {
                        stor.push(j);
                    }
                }
            }

            var node = document.getElementById("videoPointContent").childNodes[2]

            for (let i = 0; i < node.childNodes.length; i++) {
                if (node.childNodes[i].value != undefined) {
                    var value = node.childNodes[i].value;
                    var valueo;
                    for (let j = 0; j < dict.length; j++) {
                        if (value == dict[j]) {
                            valueo = j;
                            for (let k = 0; k < dict.length; k++) {
                                if (valueo == stor[k]) {
                                    node.childNodes[i].click()
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            }

            if (document.getElementsByClassName("cbtn")[0]) {
                console.log("答案点击");
                document.getElementById("closePointId").childNodes[1].click()
                console.log("提交答案");
                console.log("完成✅");
            } else {
                console.log("等待窗口弹出✅");
            }
            console.log("_________________________");
        } else {

            console.log("判断题");
            if (document.getElementsByClassName("ctit")[0].innerHTML.search("判断题") >= 0) {
                // var answer = document.getElementById("PointQuestionAnswer0").childNodes[0].childNodes[0].innerHTML.search('正确') >= 0;
                for (let i = 0; i < document.getElementById("videoPointContent").childNodes[2].childNodes.length; i++) {
                    var ele = document.getElementById("videoPointContent").childNodes[2].childNodes[i].value;
                    if (ele == 'Y' || ele == 'N') {
                        document.getElementById("videoPointContent").childNodes[2].childNodes[i].click();
                        console.log("答案点击");
                        document.getElementById("closePointId").childNodes[1].click()
                        console.log("提交答案");
                    }
                }

                console.log("完成✅");
            } else {
                console.log("非单选题或多选题或判断题❌");
            }
        }
    } else {
        console.log("等待窗口弹出✅");
    }
}

var times = 0;
setInterval(() => {

    function getVideoPlayTime(videoTime) {
        var now = Number(videoTime.split('/')[0].split(':')[0]) * 60 + Number(videoTime.split('/')[0].split(':')[1])
        var total = Number(videoTime.split('/')[1].split(':')[0]) * 60 + Number(videoTime.split('/')[1].split(':')[1])
        return { now, total }
    }

    times++;
    var videoTime = document.getElementsByClassName("timeNum")[0].innerHTML
    theTime = getVideoPlayTime(videoTime)
    console.log("🔔循环执行第" + times + "次", " 计时" + (times * 10 / 60).toFixed(2) + "分", "当前视频时间:" + videoTime, theTime.now, theTime.total);
    if (theTime.now >= theTime.total) {
        document.getElementsByClassName("vmFront")[0].click()
    }

    if (times % 3 == 0) {
        document.getElementById("my-video").playbackRate = 1.25
    } else {
        document.getElementById("my-video").playbackRate = 1.15
    }

    switch (times % 3) {
        case 0: document.getElementById("my-video").playbackRate = 1.25
            break;

        case 1: document.getElementById("my-video").playbackRate = 1.20
            break;

        case 2: document.getElementById("my-video").playbackRate = 1.00
            break;
    }

    // document.getElementById("my-video").playbackRate = 1.25
    // document.getElementById("my-video").playbackRate = 1.25
    // document.getElementById("my-video").playbackRate = 1.25

    if (document.getElementsByClassName("vplay vmPlay").length != 0) {
        document.getElementsByClassName("vplay vmPlay")[0].click()
    }

    execute();
}, 1000 * 10);

console.log("👌部署成功 等待执行");