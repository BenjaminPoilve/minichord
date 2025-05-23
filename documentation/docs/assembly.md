> **Note: While the minichord kits are not yet for sale, they might be soon. To be informed about the project and the release date of those kits, please subscribe to [the newsletter](https://buttondown.com/BenjaminPoilve).**


# **Assembly notes**

Please note that depending on the kit version, you may not have to follow all the steps:

* If you are building a minichord from scratch, start at [PCB Manufacturing](#pcb-manufacturing)
* If you have a minichord kit start at [Enclosure Manufacturing](#enclosure-manufacturing)

In any case, bill of material (BOM) and necessary tools are listed at the beginning of each section.

# **PCB Manufacturing**

Manufacturing files for the PCB are available in the [Source section](/source) in Gerber format. 


![the two minichord PCB](./ressources/both_pcb.jpg "the two minichord PCB")


A minichord is composed of two PCB:

* The main PCB that is a four layer 1.6mm board;
* The touch zone PCB that is a two layer 1.6mm board (please remember that this PCB will be visible, so choose colour accordingly and remove any marking that the fab house would like to add). 

Any good fab house should accept those files for manufacture.

# **SMD Soldering**

The main PCB requires some SMD components. The list if available [here](https://github.com/BenjaminPoilve/minichord/blob/main/hardware/BOM/electronics_BOM.csv). If you are experimented with SDM soldering it is possible to do that step yourself. However it requires quite advanced capabilities to properly solder the IC packages used. 

For the placement of the component, please refer to [this document](./ressources/smd_assembly/g66188.png).

For the manufacturer reference of the different components, please refer to [this document](https://github.com/BenjaminPoilve/MiniChord/blob/main/hardware/BOM/electronics_BOM.csv).

Once all the component are soldered, your PCB should look like this:

![After SMD assembly](./ressources/smd.jpg "after SMD assembly")


# **Through-hole soldering**

<details>
    <summary> <b>BOM</b> </summary>
<table class="table table-striped table-hover">
<thead>
<tr>
<th><strong>ID</strong></th>
<th><strong>Part</strong></th>
<th><strong>Link</strong></th>
<th><strong>Quantity</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>D1</strong></td>
<td>Red LED</td>
<td><a href="https://www.mouser.fr/ProductDetail/604-WP169XID">Mouser</a></td>
<td>1</td>
</tr>
<tr>
<td><strong>D2</strong></td>
<td>5mm RKGB LED</td>
<td>-</td>
<td>1</td>
</tr>
<tr>
<td><strong>J2</strong></td>
<td>Switched Audio Jack&nbsp;</td>
<td><a href="https://www.mouser.fr/ProductDetail/490-SJ-3566AN">Mouser</a></td>
<td>1</td>
</tr>
<tr>
<td><strong>J3</strong></td>
<td>JST PH 2mm 2pin male angled</td>
<td>-</td>
<td>1</td>
</tr>
<tr>
<td><strong>N/A</strong></td>
<td>503450 1000mAh battery</td>
<td>-</td>
<td>1</td>
</tr>
<tr>
<td><strong>&gt;&nbsp; RV1-RV3</strong></td>
<td>Potentiometer</td>
<td><a href="https://www.mouser.fr/ProductDetail/317-2090F-100K">Mouser</a></td>
<td>3</td>
</tr>
<tr>
<td><strong>&gt;&nbsp; SW22, SW24, SW25, SW26</strong></td>
<td>Tactile switch 6x6mm</td>
<td><a href="https://www.mouser.fr/ProductDetail/653-B3F-1050">Mouser</a></td>
<td>4</td>
</tr>
<tr>
<td><strong>&gt;&nbsp; SW1-SW21</strong></td>
<td>Tactile switch 12x12mm</td>
<td><a href="https://www.mouser.fr/ProductDetail/653-B3F-4050">Mouser</a></td>
<td>21</td>
</tr>
<tr>
<td><strong>&gt;&nbsp; J1, J4</strong></td>
<td>Touch header female</td>
<td><a href="https://www.mouser.fr/ProductDetail/855-M20-7810345R">Mouser</a></td>
<td>2</td>
</tr>
<tr>
<td><strong>N/A</strong></td>
<td>Touch header male</td>
<td><a href="https://www.mouser.fr/ProductDetail/855-M20-8760346">Mouser</a></td>
<td>2</td>
</tr>
<tr>
<td><strong>U1</strong></td>
<td>Teensy 4.0</td>
<td>PJRC</td>
<td>1</td>
</tr>
<tr>
<td><strong>N/A</strong></td>
<td>Teensy headers</td>
<td><a href="https://www.mouser.fr/ProductDetail/200-TSW13220TS">Mouser</a></td>
<td>1</td>
</tr>
</tbody>
</table>


<p>To facilitate ordering from Mouser, here is a <a href="https://www.mouser.fr/api/CrossDomain/GetContext?syncDomains=www&amp;returnUrl=https%3a%2f%2fwww.mouser.com%2fProjectManager%2fProjectDetail.aspx%3fAccessID%3d8661b1e86b&amp;async=False&amp;setPrefSub=False&amp;clearPrefSub=False">prefilled basket</a>. </p>
</details>

<details>
    <summary> <b>Tools</b> </summary>
    <ul>
<br>
<li>Soldering iron and solder wire; </li>
<li>X-acto knife (or another precise cutter);</li>
<li>Diagonal cutting pliers (the Knipex "Super Knips" are worth the price);</li>
<li>[Optional] Multimeter.</li>
</ul>
</details>
<hr>

Before starting the soldering, it might be useful to identify the position of each component and do a dry run assembly. This will ensure you properly identify the position of each part and, in consequence, that you indeed have all the components of the BOM. 

## Teensy preparation 

Before soldering, some small modifications need to be made to the Teensy 4.0 Board. 

**The onboard led needs to be disabled**. This step is purely aesthetic so if you don't feel confortable doing that modification it is ok (it will simply give your minichord a soft orange glow). 

The led is next to the pin 13 of the Teensy. To identify it, simply plug your teensy using a micro USB cable. The led will blink.

![identifying the led](./ressources/teensy_led.jpg "identifying the led")

There is a trace on the top side between the led and the reset pushbutton. Cut that trace using the X-acto (the specific position is in red in the image below). 

![cutting the led](./ressources/teensy_cut.jpg "cutting the led")


Plug the Teensy again, and check that the led is not blinking anymore. To make sure that you did not damage the Teensy, you can simply use the Teensyduino program to upload any sketch and check that it is still working normally (while the led is not glowing). 

**Then we need to cut the USB power**. This step is not optional as it allows battery to function as expected. USB power will then be routed to the battery for charging and the Teensy will only be powered when an audio jack is inserted. 

There is pads on the belly of the Teensy specifically for that reason. It is situated next to the 5V pin. With the X-acto, cut the trace between the two exposed pads. 

![cutting the VUSB](./ressources/teensy_power_cut.jpg "cutting the VUSB")


Once it is done, it's a good idea to check with a multimeter that there is indeed no contact between the two pads. 

![checking the cut](./ressources/teensy_power_check.jpg "checking the cut")




## Pushbuttons soldering

### 12x12mm pushbuttons

Let's start with the 12x12mm pushbuttons. The first step is to insert them all (21) on the PCB. It is a close fit, so to make it easier start with the middle line of buttons. 

![putting the buttons in place](./ressources/button_insertion.jpg "putting the buttons in place")

They need to be pushed firmly onto the PCB to properly latch. Make sure that they are all in place and seating flat before starting the soldering. 

![soldering the buttons](./ressources/button_soldering.jpg "soldering the buttons")
 

### 6x6mm pushbuttons

The process is very similar to the 12x12mm button. First insert all the four pushbuttons, making sure they are fully seated before soldering.

Once done your PCB should look like this:

![after soldering all the buttons](./ressources/small_soldered.jpg "after soldering all the buttons")


## Audio jack soldering

As before, make sure the jack is fully seated before soldering. 

![soldering the jack](./ressources/jack_solder.jpg "soldering the jack")


> Note: in PCB v0.3 and before, it is necessary to:

> * cut the top left contact of the Audio jack before soldering (when looking from the top of the PCB, with the jack entry at the bottom);
> * add  a 10k pulldown resistor between the enable and ground pin of the jack (both at the center of it).

## Led soldering 

Two leds need to be soldered. 

**First the RGB led**. The provided led is a RKGB led. Those letters indicate the order of the pins, with R, G and B for the individual colours and K for the common cathode. The K pin is the longest and the position of each pin is indicated on the PCB itself. 

The RGB led needs to be fully seated in place before soldering. 

![soldering the RGB led](./ressources/led_rgb.jpg "soldering the RGB led")

Once soldered, cut the lead flush with the diagonal cutter. 

**The next one is the red led**. The longest pin is the +, and the position of each pin is indicated on the PCB itself. 

This led should not be fully seated. the top of the led should be about the level of the top of the pushbutton next to it.

![soldering the red led](./ressources/led_red.jpg "soldering the red led")

Once soldered, cut the leads flush with the diagonal cutter. 

## Header soldering

Now we need to solder the female header that will allow the touch PCB to connect. 

Those headers are really SMD components but they are really easy to solder. Just put them in place, making sure they are flush (they should hold in place) and solder each pin. 

![soldering the headers](./ressources/header.jpg "soldering the headers")

## Teensy soldering

First prepare the headers using the X-acto knife. You will need:

* Two 14-long header strip for each side of a Teensy;
* A lone header for the out-of-row contact for the VUSB pin. If you are unsure which pin it refers to, take a moment to look at the [Teensy pinout card](https://www.pjrc.com/teensy/card10b_rev2_web.pdf) to identify it and locate its position on the PCB. **Failure to place correctly that header will keep the battery from charging.**

Now you can place the headers on the board, with the short length on the Teensy's side. **Position the Teensy, belly up**, and make sure it is correctly seated. You can then solder the two end of each header line to "tack" the header in place. 

![tacking the Teensy](./ressources/teensy_tacking.jpg "tacking the Teensy")

Check that the Teensy is well seated, then do the same on the PCB's side. After a final check that the Teensy is well seated, you can then go over all the contact, both on the Teensy and on the PCB's side and solder them. **Don't forget to solder the VUSB pin**. 

![soldering the Teensy](./ressources/teensy_soldering.jpg "soldering the Teensy")


## Potentiometers

First place the three potentiometer. 

![installing the potentiometers](./ressources/potentiometer_install.jpg "installing the potentiometers")

Note that a low-profile trace is used, which means that the potentiometer sit deeper than they usually would. Make sure that they are fully seated. 

![well seated potentiometer](./ressources/potentiometer_seat.jpg "well seated potentiometer")

They will hold in place while you solder them. 

## Battery connector

This component is on the backside of the PCB. The silkscreen show the correct position for the connector, so place it accordingly.

**If the connector is installed backward and the battery is connected that way, it will destroy the device**. You need to make sure that when the battery will be connected, the polarity will be respected. 

![positionning the connector](./ressources/connector_position.jpg "positionning the connector")

> Note: If you purchased the battery yourself, you need to make sure the connector attached to it is not reversed, as it sometimes happen. In that case choose the orientation of the connector to solder to make sure that the red wire of the battery indeed is connected to the positive side (following the silkscreen marking). 

## Cutting excess leads in the battery zone 

On the backside on the PCB note a white silkscreen rectangle showing the position of the battery inside the enclosure. 

![battery zone](./ressources/battery_zone.jpg "battery zone")

Using diagonal cutters, make sure to cut any leads whithin that white rectangle that is protruding more than 1mm. This is to avoid having those leads touch the battery pouch and potentially damage them 

![cutting excess](./ressources/cutting_battery.jpg "cutting excess")


## Soldering of touch zone PCB

The last bit of soldering needed is the headers on the touch zone PCB. Once again, those are technically SMD components, but easy enough to solder. Just make sure they are well aligned. 

![touch zone pcb soldering](./ressources/solder_touch.jpg "touch zone pcb soldering")


# **Firmware uploading**

<details>
    <summary> <b>BOM</b> </summary>
    <ul>
<br>
<li>Fully assembled minichord PCB; </li>
<li>503450 1000mAh battery;</li>
</ul>
</details>
<details>
    <summary> <b>Tools</b> </summary>
    <ul>
<br>
<li>Micro USB cable (make sure it supports data transfert); </li>
<li>Computer (whether Windows, OSX or Linux);</li>
<li>Headphones;</li>
</ul>
</details>
<hr>

## Testing the board

First it is necessary to make sure the board is properly functioning. 

Without plugging the battery, plug in the micro USB. The power status led should light up (green or red depending on the specific led model). 

![first led test](./ressources/ok_led.jpg "first led test").

If it does not light up, one the most likely reason is that you forgot to solder the VUSB header. Go back to the [Through-hole soldering](#through-hole_soldering) section and read carefully the part about the Teensy soldering. 

Then plug in the battery. **Make sure that the polarity is respected** (it should be the case if you followed previous instructions). This time the led will be red, indicating that the battery is charging. 

![second led test](./ressources/ok_led_red.jpg "second led test").

## Installing the Teensy Loader Application

Next you need to install the application that will allow to upload the firmware. It is provided by PJRC and precise instruction for it are available [on their website](https://www.pjrc.com/teensy/loader.html).

Please note that if you have TeensyDuino installed, the Teensy Loader is included with it. 


## Uploading the firmware

To upload the firmware, please use the following steps:

* Plug the battery into the minichord;
* Plug in the micro USB cable between the minichord and your computer;
* Plug the headphone into the minichord 
* Open the Teensy Loader; 
* Download the hex file of the firmware from the [Source section](/source);
* Drop the hex file on the Teensy loader;


Once all those steps are done, use a header to push on the reset button of the Teensy through the PCB hole. 

![resetting the Teensy](./ressources/reset_teensy.jpg "resetting the Teensy")

If you carefully followed those steps, the Teensy Loader will indicate "Download Complete" then "Reboot OK". The main colour led of the PCB should light up. 

![the board if functionning](./ressources/board_ok.jpg "the board if functionning")

You can test it by putting the headphones to your hears and push one of the 12x12mm buttons. If you don't hear anything, check that the potentiometers are not turned fully counter-clockwise.

# **Enclosure manufacturing**

The enclosure is composed of two part, the top and the bottom shell. The STL file for those parts is available in the [Source section](/source).

> Note: This section show an earlier version of the enclosure


## Printing the parts

Depending on what equipment you have available, **you can choose different alternatives for manufacturing**. 

### FDM printing

If you have a FDM printer, you can use it to make the top and bottom shell. They fit comfortably on a 18x18cm bed. Make sure that you flip the objects to have the flat surface on the bed, no support is required for printing. 

Indicatively, on my Prusa Mini+:

* the top shell takes 2 hours to print on a 0.15mm layer height;
* the bottom shell takes 2 hours and 15 minutes to print on a 0.15mm layer height.

The result is satisfactory, though not great. 

![FMD shells](./ressources/fdm_shells.jpg "FMD shells")



#### SLA resin printing 

For better quality part, SLA resin printing is an economical alternative. Though the equipment is costly, multiple vendors offer affordable online printing services. 

It should cost less than 5€ per part for basic resin choices, for very qualitative parts. Currently 9600 resin is my favorite for a low cost and good quality. 

![Resin shells](./ressources/6060_resin.jpg "Resin shells")

It also possible (for a cost around 1.5x to 2x) to print those part with a transparent resin. 

![Transparent shells](./ressources/transparent.jpg "Transparent shells")

Whether normal or transparent resin, it is possible to use GTC liquid dyes to dye the part, for a very good final result.

![coloured shell](./ressources/dyed_shell.jpg "coloured shell")


# **Final assembly**

<details>
    <summary> <b>BOM</b> </summary>
    <ul>
<br>
<li>Fully assembled minichord PCB; </li>
<li>Fully assembled touch zone PCB; </li>
<li>Keycap set; </li>
<li>503450 1000mAh battery;</li>
<li>Top and bottom shells;</li>
<li>6x M2.3x8 self-tapping screws;</li>
<li>3x M2.3x6 self-tapping screws;</li>
<li>Double-sided tape.</li>
</ul>
</details>
<details>
    <summary> <b>Tools</b> </summary>
    <ul>
<br>
<li>X-acto knife (or another precise cutter); </li>
<li>Phillips electronics screwdriver.</li>
</ul>
</details>
<hr>

## Marking the keycap 

The first row of keycaps need to be marked with the chord letters. If you have a CNC router, then it is possible to engrave the keycap with a 45° V cutter, using a V-carve mode. 

For Omron Keycap, I've found the following setting to be satisfying:

* 300 mm/min feed rate; 
* 150 mm/min plunge rate; 
* 10 000 rpm.

![CNC engraving](./ressources/CNC_routing.jpg "CNC engraving")

Once the keycap are engraved, the engraving is filled using Markal "Lacquer fill-in" paint stick. The following steps are recommanded: 

* "sharpen" the paintstick with an X-acto to have a pointy end;
* overfill the engraving with color;
* wait for at last 15 hours for the paint to start solidifying;
* buff the surplus color out. Place a tissue paper flat on a table, and rub the keycap on it while maintaining it very flat to remove the color outside of the groove. You may need to do it in several passes, changing the tissue paper in between. To properly remove all remaining color, a few drops of isopropyl might help. 


![keycaps](./ressources/keycap.jpg "keycaps")

Alternatively, if you don't have a CNC router, you can look into UV DTF transfers. It is a cheap method to allow color tranfers that can work for details up to 0.5mm. 

Once you engraved keycap are finished, you can install all the buttons on the main PCB. 

The engraved buttons go on the first line, and the order is F,C,G,D,A,E,B from left to right 

![all buttons installed](./ressources/all_buttons_installed.jpg "all buttons installed")

## Assembling the enclosure

Now the easiest step ! 

![all components](./ressources/all_components.jpg "all components")

To avoid any screw breakage, please follow closely the following instruction:

* Use a adequately sized screwdriver. In particular, if you screwdriver slips, it might strip the screw and make the assembly impossible;
* Pre-tap the holes on the top shell. To do that, use one of the three _small_ screw. Simply fully screw it into each one of the hole, then take it out. Repeat for each of the six holes. Do not use one of the long screw for that step.


Now to the assembly itself :

First add a strip of double sided tape on the battery to install the battery in the dedicated space on the bottom shell. 
![install battery](./ressources/install_battery.jpg "installing the battery")

Then connect the battery to the PCB. Add a material on top of the battery to protect againt any contact (bubble wrap, foam board, etc.).
![connecting the battery](./ressources/battery_connection.jpg "connecting the battery")


You can then put the PCB in place (it should snap fit into place) and secure it with the three small screws. Be sure to not overtighten the screws: once you feel a resistance, it is enough. 

![bottom installed](./ressources/bottom_installed.jpg "bottom installed")

No install the top shell. Make sure that all keycap are well-aligned with their respective holes. Once it is the case, it should be easy to push the top shell in place. 

Secure the top shell with the six long screws. Be sure to not overtighten the screws: once you feel a resistance, it is enough. 

![top installed](./ressources/top_installed.jpg "top installed")

The last step is to install the touch zone PCB. Simply be carefull that the header are in their right place, and push it until it makes contact with the shell. 

![finished](./ressources/finished.jpg "finished")

That's it, your minichord is done! No to use it, please refer to the ["manual" section](/user_manual)
