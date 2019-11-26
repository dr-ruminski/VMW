# VMW
**V**irbo **M**otors **W**earable is an open-source device for enhancing Mixed Reality applications with tactile human-machine hand interactions. The presented device is capable of providing tactile feedback while interacting with virtual objects, e.g., when elements of a 3D user interface are touched. The device enables to run vibro motors mounted on a user's fingers while interacting with synthetic objects.
In order to control the vibe of a particular vibro motor in a wireless manner, an HTTP-based API has been developed. 
The API can be used to develop mobile-tactile Mixed Reality applications to enhance user experience by giving an impression of fading in/out effects when interacting with 3D objects. Also, it is possible to implement short and straightforward tactile feedback when touching elements of a 3D user interface, e.g., a 3D button, to confirm the user that a virtual object has been successfully pressed in 3D space.



## Hardware
The VMW device consists of five vibro motors connected to the device’s board, each mounted on a user’s fingers (Fig. 1A). An ESP8266 microcontroller serves as an asynchronous server providing an HTTP-based API for controlling voltage of each sensor (Fig. 1B). Furthermore, a lithium-ion battery supplies voltage to the device (Fig. 1C). Finally, a regulating velcro strip is used with the mounted ESP8266 board in order to make it easy to put the device on the user’s hand (Fig. 1D).
<figure>
  <img height="300" src="/Publication/Figures/device_blue.png?raw=true">
  <figcaption>Fig.1 - Vibro Motors Wearable.</figcaption>
</figure> 

The device is lightweight and easy-to-wear on a hand. It does not limit the user’s hand movements. It is supplied with a small, rechargeable LI-ION battery. Alternatively, it can be connected to the 3.3V power supply with wires.
In order to control the vibe of a particular vibro motor in a wireless manner, we have developed a simple-to-use HTTP-based API. For instance, to run a vibro motor with 3.3V mounted on an index finger, an AR or VR application should call HTTP GET method with the following pattern:
```
http://device-ip-address/motor?finger=index&voltage=3.3
```
where:
* *device-ip-address* – is an IP address of a Vibro Motors Wearable device;
* *finger* – is a parameter that expresses which vibro motor should be run;
* *voltage* is a parameter that indicates which voltage should be supplied from the range [0, 3.3].

## Software

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

<figure>
  <img height="300" src="/Publication/Figures/me_at_ismar.jpg?raw=true">
  <figcaption>Fig.3 - Me presenting at ISMAR 18.</figcaption>
</figure> 
