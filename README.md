# OOP_Assign2
Upgrading a Class - AmFm Radio


Upgrading Your Car Radio
C++ - Winter 2014 – Page 1Feb 28, 

Retrieve and use the CarRadio-StartingPoint.zip file from ... as your starting point. The CarRadio
example provided above is an okay one but is significantly flawed in a lot of ways. Your task in this
assignment is to take this “okay” class definition and make it better and more general by improving it
in the following ways:
Generalizations:
• Change the names of the two class-related files to amfmRadio.h and amfmRadio.cpp.
• Change the name to AmfmRadio as this class no longer should be tied into only being in a car.
• Rename the struct Button to struct Freqs, since we're going to use the struct for more than buttons.
o Change AMButton to AMFreq and FMButton to FMFreq.
Additions & Replacements:
• Replace the existing constructor with two constructors that initialize all private data and that use the
following parameters to initialize the appropriate data:
o one that takes a single bool parameter that indicates whether the radio should be on or not
when instantiated. Give this parameter a default of false (as discussed in Week 1).
o one that takes a single bool parameter that indicates whether the radio should be on or not
when instantiated and an array of 5 struct Freqs that contains the initial button values.
• Add a destructor that simply displays "Destroying AmfmRadio".
• Instantiate an instance of AmfmRadio with the power initially on (as fed to the constructor as a
parameter) in the mainline.
• Add a method called ScanDown() that behaves similarly to ScanUp(), except that the scanning is down.
o Make menu entry #8 correspond to "Scan Down". Make menu entry #9 correspond to "Quit
the program".
 Do not otherwise change the user interface.
 I'm serious.
• Create a mutator for the current_station data member.
• When switching from AM to FM (and vice versa), go immediately to the previous frequency tuned on
that band.
o e.g. if you're listening to 700 on AM and switch to FM and then back to AM, make sure that
you go to 700, not 530.
o Hint: it would be a good idea to use a new data member of type struct Freqs.
• When turning the radio on after being off, go immediately to the previous band (AM or FM) and last
frequency tuned on that band.
o e.g. if you're listening to 92.9 on FM and turn the radio off, turning the radio on again should
tune to 92.9 on FM.
o Hint: the previous hint works here too.
• When turning the radio off, turn the volume down to 0. When turning the radio back on, restore the
previous volume level.
o Turn the volume level to 0 when the radio is turned on for the first time.
• Create a second version of SetVolume(). The second one takes a volume as a parameter. The reason
for this addition is so that someone using SetVolume() can get the value in their own way and pass it to
the method.
o You will not be using this second version in this assignment. You will be using it in a later
assignment.
• Change ScanUp() so that it can be called without any output being displayed. If you have any other
methods (except ShowCurrentSettings() ) that display output, make it possible for them to be called
without any output being displayed.
o Note that this does not mean that you should totally eliminate output being displayed but
should make output display optional.
o This does not apply to ShowCurrentSettings(), as its entire purpose is to display output.
o Suggestion: Create a private bool variable that keeps track of whether or not output should be
displayed (except ShowCurrentSettings() ).
o Reasoning: You will be inheriting from this class in a later assignment and you don't want to
display output from the parent class when you'll be doing it from the child class instead. The
child class will contain the user interface to be used for that assignment.
• Create accessors for all private data members.
Style and Convention Requirements
• Make any new data members that you create private.
• Put all new code bodies in amfmRadio.cpp.
• Your code must not unnecessarily duplicate similar code segments. Make use of your methods (e.g.
the mutator mentioned above) appropriately.
• Using the what was called the classic commenting style in the lessons,
o Add full file header / class header comments in each of your three source files (yes, even the .h
file). For the descriptions of each, describe what is done (generally) by the contents of the file
being commented.
o Add full method header comments on each method you develop and don’t forget your inline
comments as well
o Make sure that all comments that already exist in the example are correct. Yes – even when
you take over someone else’s code – you become responsible for their comments!
Other Stuff
• If you want to create additional methods or data members, you can.
• If you want to put the data members in a struct, you can (although this is not necessary and adds an
extra layer of referencing)
• Please realize that not all of the changes that you are making will be used in this assignment.  We are
trying to design the class to be more useful in general. We will be using many of the changes in
subsequent assignments.
• Also realize that some of the requirements above have already been implemented.
• ZIP up the source files : amfmRadio.h, amfmRadio.cpp, and driver.cpp and submit them to the D2L
dropbox by the deadline.
