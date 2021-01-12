# RemoteLightOnOff-OwnProject-

개요 
---

<img width = "300" height = "500" src="https://user-images.githubusercontent.com/59462895/104285554-2affe200-54f7-11eb-96e4-cf2e5c373847.gif" width="90%"></img>

이 프로젝트는 불을 원격으로 끄고 키는 것을 제어하는 기기를 만드는 개인 프로젝트이다.
___
개발배경 및 목적
---
   
<img width = "200" src="https://user-images.githubusercontent.com/59462895/104279680-09e6c380-54ee-11eb-9a1d-cc4935dac7a1.jpg" width="90%"></img>

위 와 같이 문 사이에 있는 스위치를 보고 아이디어를 생각했다. 문틈 사이에 손을 넣었다가 다른 누군가가 문을 닫으면 손이 찧일 수도 있어 위험했다. 이러한 부분을 없앨 수 있도록 원격으로 스위치를 제어할 수 있는 것을 생각하고 개발하게 되었다.

사용 장비
---   
|esp8266|servo motor|relay|IR sensor kit|cable|
|--|--|--|--|--|
|<img width = "150" src="https://user-images.githubusercontent.com/59462895/104279739-22ef7480-54ee-11eb-9900-e833ba3f7c8f.jpg" width="90%"></img>|<img width = "150" src="https://user-images.githubusercontent.com/59462895/104279747-284cbf00-54ee-11eb-8a53-e4e249620be8.jpg" width="90%"></img>|<img width = "150" src="https://user-images.githubusercontent.com/59462895/104279741-2551ce80-54ee-11eb-8313-38e3d965dbc2.png" width="90%"></img>|<img width = "150" src="https://user-images.githubusercontent.com/59462895/104279842-4fa38c00-54ee-11eb-9bb3-c57655f8418e.jpg" width="90%"></img>|<img width = "150" src="https://user-images.githubusercontent.com/59462895/104279861-57fbc700-54ee-11eb-84be-582802e5ffc5.jpg" width="90%"></img>|
|ESP-12 WeMos D1 mini|SG-90|SRD-05VDC-SL-C||

회로도
---
<img width = "600" src="https://user-images.githubusercontent.com/59462895/104279732-208d1a80-54ee-11eb-816b-4a5ea70d739f.JPG" width="90%"></img>
   
여기에서 건전지를 이용한 것이 아닌 케이블의 피복을 까서 5v 선과 gnd 선을 이용해서 전원을 공급하였다.

완성된 모습
---
|내부 모습|외부 모습|
|--|--|
|<img width = "400" src="https://user-images.githubusercontent.com/59462895/104289989-1b839780-54fd-11eb-9e2d-ec8010d5c631.jpg" width="90%"></img>|<img width = "380" src="https://user-images.githubusercontent.com/59462895/104290039-2ccca400-54fd-11eb-8a37-7136e5e46ef8.jpg" width="90%"></img>

 - 설치된 모습   


<img width = "300" src="https://user-images.githubusercontent.com/59462895/104289993-1de5f180-54fd-11eb-9553-6fc2afddef32.jpg" width="90%"></img>|

사용 방법
---
1. [adafruit](https://ifttt.com/adafruit)에 가입하고 io Dash 에 Light 버튼을 형성해주고 on은 1의 값 off는 0의 값을 입력하도록 설정해준다.
2. My Key 에 들어가 자신의 아이디와 api 키 값을 확인한다.

<img width = "500" src="https://user-images.githubusercontent.com/59462895/104286871-fd1b9d00-54f8-11eb-9281-8793f0fed57e.JPG" width="90%"></img>

3. config 에 있는

```
#define IO_USERNAME ""
#define IO_KEY ""
```
 의 빈칸에 자신의 아이디와 api 키 값을 입력해준다.

4. 또한 

```
#define WIFI_SSID ""
#define WIFI_PASS ""
```
여기에 자신이 사용하는 와이파이의 이름과 비밀번호를 입력해준다.

5. 여기에서 [adafruit](https://ifttt.com/adafruit) 사이트에 가입한 뒤에 IF'T'TT 인 첫번째 This 에는 구글 어시스턴트를 선택해주고, 두번째 IFTT'T' 에서는 adafruit 을 설정해준다.

<img width = "300" src="https://user-images.githubusercontent.com/59462895/104288007-94352480-54fa-11eb-9851-273337dadb05.JPG" width="90%"></img>

그 후, 첫번 째에는 말하고자 하는 입력어를 넣어준다. response 질문에는 어시스턴트가 대답하는 문구를 입력한다. 보낼 adafruit의 feed의 이름은 Feed name 란에 입력해주고 Data to save 란에 값을 넣는다.
(이와 같이 키는 동작도 하나 만들어준다.)

6. esp 8266 에 esp8266_LightOnOff.ino 를 Arduino 소프트웨어를 사용해서 프로그램을 업로드 시켜준다.

7. 회로를 위의 회로도와 같게 구성하면 사용할 수 있다.

시연
---
- 리모컨   


<img width = "300" src="https://user-images.githubusercontent.com/59462895/104288547-4cfb6380-54fb-11eb-861f-8eac35a5e0c8.gif" width="90%"></img>   
- 구글 어시스턴트   

<img width = "300" src="https://user-images.githubusercontent.com/59462895/104288560-4ff65400-54fb-11eb-9974-271eaae5e97b.gif" width="90%"></img>

- 밖에서 구글 어시스턴트   

<img width = "300" src="https://user-images.githubusercontent.com/59462895/104288569-5258ae00-54fb-11eb-8adb-6d1689ced5ff.gif" width="90%"></img>
