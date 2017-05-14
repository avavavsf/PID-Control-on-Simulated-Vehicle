# PID Control on Simulated Vehicles

## 1. Describe the effect each of the P, I, D components had in your implementation.

The P component provides a steering angle response that is proportional to the cross-track error (CTE). When a value of 0.1 is used for the P coefficient, it can be seen that the car responds to the CTE by swaying to the left or right. This response on its own overshoots the desired behaviour and results in larger and larger oscillations.

The D component provides an additional response that is proportional to the change in the value of the cross-track error. When a value of 3 is chosen for the D coefficient, it can be seen that the oscillations are no longer increasing and the car stays within the limits of the track.

The I component provides an additional response that is proportional to the integrated value of the cross-track error. When a value of 0.01 is used, the bias of the steering is overcome and the car no longer has less of a preference to veer right.

## 2. Describe how the final hyperparameters were chosen.

The final hyperparameters were chosen by manual tuning iteratively, even though the Twiddle code is there but did work very well in my case. 
* Started by setting all PID coefficients 0, the car would drive completely straight with no error response. 
* Then increased the P component until it demonstrated a significant response to the cross-track error. I settled at 0.1 for P componet coeffient.
* The oscillations of the car increase over time with only P component. So I increased the D component of the PID until the  the car did not go outside the track. Finally 3.0 was used for the D component.
* Finaly incremented the I component to make the responses a little bit smoother. A value of 0.003 was sufficient. The final performance can be seen above in the video link.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
