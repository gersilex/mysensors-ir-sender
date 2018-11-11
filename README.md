IR Sender
=========

Arbitrary IR code sender for MySensors-compatible boards. The data you send is parsed and fed into
the send function of [cyborg5/IRLib2](https://github.com/cyborg5/IRLib2). This eliminates the need
to re-program the device to send new IR codes. This also limits the maximum length of the code to
the length of the MySensors message. Usually you will not hit this limit with most commercially
available devices. Use any software to build the protocol, code and length, separated by commas and
send it to this device as string. Please see the message format below.

Message Format
--------------

Use the "receive" example of the IRLib2 library to find out the values.

Message Format: `<PROTOCOL NUMBER>,<HEX IR CODE>,<LENGTH>`
Message Examples:

```plaintext
1,20DEFF,32    <= NEC Protocol, Code 0x20DEFF, 32 bits
1,4FD2,16      <= NEC Protocol, Code 0x4FD2,   16 bits
```

Reference: Protocol Numbers: [<IRLibProtocols.h> of cyborg5/IRLib2](https://github.com/cyborg5/IRLib2/blob/master/IRLibProtocols/IRLibProtocols.h)

Installation
------------

Use [Platformio](https://platformio.org/) to install the dependency or find them in `platformio.ini` and collect and add them to your IDE manually.

License
-------

(c) 2018 by Leroy Foerster <gersilex@gmail.com>
Released under the MIT License
