ArduSat2SDK
===========

Common drivers, Arduino libraries, and examples for ArduSat-2 experiments

# Layout

* Arduino libraries live in `arduino`
* The general I2C interface, and driver common code lives in `src` and `include`

# Architecture

Drivers in this library use a C based API to ensure compatibility with multiple
subsystems and architetures. Since this code is also the basis of the public
ArduSat2 SDK, an Arduino implementation of the common layer is provided as the
`ArduSat2` Arduino library.

# Using the Arduino Libraries

Before the libraries can be used in an Arduino sketch, the common driver code
needs to be packaged alongside the various libraries. To do this, simply run:

        $ ./waf configure package

In the `build` directory, there will be a zip that contains the all the Arduino
libraries, ready for import into a project.
