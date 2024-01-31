![image-20231228141441210](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228141441210.png)

![image-20231228141450115](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228141450115.png)

1. Is your browser running HTTP version 1.0 or 1.1?  What version of HTTP is the server running?

Browser: HTTP/1.1

We can see browser send a packet with Request Version: HTTP/1.1

Server: HTTP/1.1

We can see the browser receive a packet from server with Response Version: HTTP/1.1

2. What languages (if any) does your browser indicate that it can accept to the server?

Accept-Language: zh-CN,zh;q=0.9,en-CN;q=0.8,en;q=0.7,zh-TW;q=0.6\r\n

3. What is the IP address of your computer?  Of the gaia.cs.umass.edu server?

My computer: 192.168.31.23

Server: 128.119.245.12

4. What is the status code returned from the server to your browser?

200 OK

5. When was the HTML file that you are retrieving last modified at the server?

Last-Modified: Wed, 27 Dec 2023 06:59:02 GMT\r\n

6. How many bytes of content are being returned to your browser?

128 bytes

7. By inspecting the raw data in the packet content window, do you see any headers within the data that are not displayed in the packet-listing window?  If so, name one.

Nope.



![image-20231228143347850](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228143347850.png)

![image-20231228143241624](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228143241624.png)

8. Inspect the contents of the first HTTP GET request from your browser to the server.  Do you see an “IF-MODIFIED-SINCE” line in the HTTP GET?

If-Modified-Since: Thu, 28 Dec 2023 06:22:02 GMT\r\n

9. Inspect the contents of the server response. Did the server explicitly return the contents of the file?  How can you tell?

If you download this multiple times on your browser, a complete copy will only be sent once by the server due to the inclusion of the IN-MODIFIED-SINCE field in your browser's HTTP GET request to the server.

10. Now inspect the contents of the second HTTP GET request from your browser to the server.  Do you see an “IF-MODIFIED-SINCE:” line in the HTTP GET? If so, what information follows the “IF-MODIFIED-SINCE:” header?

If-Modified-Since: Thu, 28 Dec 2023 06:31:01 GMT\r\n

11. What is the HTTP status code and phrase returned from the server in response to this second HTTP GET?  Did the server explicitly return the contents of the file?  Explain.

304 Not Modified. Nope. If you download this multiple times on your browser, a complete copy will only be sent once by the server due to the inclusion of the IN-MODIFIED-SINCE field in your browser's HTTP GET request to the server.





![image-20231228145105494](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228145105494.png)

12. How many HTTP GET request messages did your browser send?  Which packet number in the trace contains the GET message for the Bill or Rights?

HTTP header:361 bytes. HTTP messages: 4500 bytes.

Frame: #13 #14 #15 #16

13. Which packet number in the trace contains the status code and phrase associated with the response to the HTTP GET request?

The first one packet #13.

14. What is the status code and phrase in the response?

200 OK

15. How many data-containing TCP segments were needed to carry the single HTTP response and the text of the Bill of Rights?

4 segments





![image-20231228154603452](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231228154603452.png)

16. How many HTTP GET request messages did your browser send?  To which Internet addresses were these GET requests sent?

    3 HTTP GET sent. Send address: 128.119.245.12 and 178.79.137.164

17. Can you tell whether your browser downloaded the two images serially, or whether they were downloaded from the two web sites in parallel?  Explain.

    According to the timestamp of two pics HTTP GET, they are parallel in order to improve user experience.



![image-20231229144402180](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/pics/image-20231229144402180.png)

18. What is the server’s response (status code and phrase) in response to the initial HTTP GET message from your browser?

401 Unauthorized

19. When your browser’s sends the HTTP GET message for the second time, what new field is included in the HTTP GET message?

Authorization: Basic d2lyZXNoYXJrLXN0dWRlbnRzOm5ldHdvcms=\r\n

The username (wireshark-students) and password (network) that you entered are encoded in the string of characters (d2lyZXNoYXJrLXN0dWRlbnRzOm5ldHdvcms=) following the “Authorization: Basic” header in the client’s HTTP GET message.