# VMW
**V**irbo **M**otors **W**earable is an open-source device for enhancing Mixed Reality applications with tactile human-machine hand interactions. The presented device is capable of providing tactile feedback while interacting with virtual objects, e.g., when elements of a 3D user interface are touched. It enables to run vibro motors mounted on a user's fingers while interacting with synthetic objects.
In order to control the vibe of a particular vibro motor in a wireless manner, an HTTP-based API has been developed. 
The API can be used to develop mobile-tactile Mixed Reality applications to enhance the user experience by giving an impression of fading in/out effects when interacting with 3D objects. Also, it is possible to implement short and straightforward tactile feedback when touching elements of a 3D user interface, e.g., a 3D button, to confirm the user that a virtual object has been successfully pressed in 3D space.



## Hardware
The VMW device consists of five vibro motors connected to the device's board, each mounted on a user's fingers (Fig. 1A). An ESP8266 microcontroller serves as an asynchronous server providing an HTTP-based API for controlling voltage of each sensor (Fig. 1B). Furthermore, a lithium-ion battery supplies voltage to the device (Fig. 1C). Finally, a regulating velcro strip is used with the mounted ESP8266 board in order to make it easy to put the device on the user's hand (Fig. 1D). The device is lightweight and easy-to-wear on a hand. It does not limit the user's hand movements. It is supplied with a small, rechargeable LI-ION battery. Alternatively, it can be connected to the 3.3V power supply. Leap Motion device has been used To track a hand and motions of fingers.
<p align="center">
    <img height="250" src="/Publication/Figures/device_blue.png?raw=true">
    <br>Fig.1 - Vibro Motors Wearable.
</p>  


## Software
### Server-side
The source code of an asynchronous server can be found within the following catalog: [VibroWearableAsyncServer-esp8266](VibroWearableAsyncServer-esp8266). The project has been created with the use of Visual Studio. 
First of all, change the SSID and password of *VibroWearableAsyncServer.cpp* to the proper access point (AP). With the use of this AP VMW will connect and be accessible by a client app in a wireless manner. 
```
const char* ssid = "ssid"; 
const char* password = "passwordToAccessPoint";
```

Compile the code and upload it to any instance of ESP 8266. You can also use node mcu. In logs, you will find a given IP address that will be used by a client application.

Next, in order to run a vibro motor with e.g., 3.3V mounted on an index finger, an AR or VR application should call HTTP GET method with the following pattern:
```
http://VMW-ip-address/motor?finger=index&voltage=3.3
```
where:
* *device-ip-address* – is an IP address of a Vibro Motors Wearable device;
* *finger* – is a parameter that expresses which vibro motor should be run;
* *voltage* is a parameter that indicates which voltage should be supplied from the range [0, 3.3].

### Client-side
To show the device's capabilities, a [demo](/Demos/Demo2-touchingPlane.html) application has been developed in which a user can experience tactile feedback while interacting with virtual objects.  The application tracks the position of a hand and fingers in 3D space, which consists of two virtual objects. When a particular finger intersects on of the virtual objects, the application sends an asynchronous HTTP GET request to run a vibro motor (Fig. 2a). The further the boundary of a virtual object is penetrated, the more requests are dynamically sent to increase the voltage of a particular vibro motor giving the user an impression of the 'fade in' effect (Fig. 2b).  Vice versa, when the user moves their hand back, the device decreases the voltage giving the user an impression of a 'fade out' effect.

The presented application also allows moving virtual objects in a 3D space. This function gives a user a possibility to test that implemented tactile feedback is not fixed, but is dependent on the position of virtual objects.
 
<p align="center">
  <table style="width:100%">
    <tr>
      <td><img height="250" src="/Publication/Figures/index_finger.jpg?raw=true"></td>
      <td><img height="250" src="/Publication/Figures/4fingers.jpg?raw=true"></td> 
    </tr>
  </table>
  <br>Fig.2 - Interacting with a virtual object. In Figure (a) the user experiences tactile feedback only on the index finger while Figure (b) presents tactile feedback differentiating for each finger.
</p>


## Publication
If you find the project interesting, I'd be grateful for citing VMW: 
```
@inproceedings{ruminski2018VMW,
  title={Augmenting Mixed Reality Applications with the Vibro Motors Wearable},
  author={Rumi{\'n}ski, Dariusz and Klinker, Gudrun},
  booktitle={2018 IEEE International Symposium on Mixed and Augmented Reality Adjunct (ISMAR-Adjunct)},
  pages={401--402},
  year={2018},
  organization={IEEE}
}
```
The above-listed publication can be found [here](Publication/VMW-ISMAR18-Munich.pdf). VMW was presented at the International Symposium on Mixed and Augmented Reality ([ISMAR'18](https://www.ismar2018.org/)) conference in Munich. 
<p align="center">
    <img height="250" src="/Publication/Figures/me_at_ismar.jpg?raw=true">
    <br>Fig.3 - Me presenting VMW at ISMAR 18.
</p>  


## Appendix
VMW was designed and developed while I was performing a 3-month research internship at the Technical University of Munich (Germany) in 2018 under Professor Gudrun Klinker's supervision. It was an honor for me to work with Professor Klinker. I'll always remember the time spent in Garching as a vast and fantastic experience. Anyway, hard time work paid off very well - made new friendships, gained research experience,  but not only. Last weekend of September I spent in the Alps. The ultimate goal of my journey was to get to Zugspitze - the highest peak of the Wetterstein Mountains as well as the highest mountain in Germany (2.962 m above sea level). Here are a few pictures presented while I was exploring the mountains. Enjoy!

<p align="center">
  <table style="width:100%" border="0">
    <tr>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/01_Zugspitze2.jpg?raw=true"></td>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/02_startingPoint.jpg?raw=true"></td> 
    </tr>
    <tr>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/03_moon_and_breakfast2.jpg?raw=true"></td>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/04_Alps2.jpg?raw=true"></td>
    </tr>
    <tr>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/05_letsGo.jpg?raw=true"></td>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/06peak.jpg?raw=true"></td>
    </tr>
    <tr>
      <td align="center"><img height="250" src="/Publication/Figures/appendix/07_meAtpeak2.jpg?raw=true"></td>        
      <td align="center"><img height="250" src="/Publication/Figures/appendix/08_window.jpg?raw=true"></td>
    </tr>
    <tr>  
      <td align="center"><img height="250" src="/Publication/Figures/appendix/09_bye.jpg?raw=true"></td>
    </tr>            
  </table>
</p>
