[How to Define Your Own assert() Macro for Embedded Systems](https://barrgroup.com/embedded-systems/how-to/use-assert-macro)

Solid code
One of the most widely cited references on the topic of assertions is Writing Solid Code.2 
I recommend it highly for its discussion of assertions as well as much of the other advice it offers.

Maguire is sometimes criticized for suggesting that assertions should not be compiled into the shipped version of the code 
(using the NDEBUG switch discussed above). 
Considering that he works for Microsoft, and he is writing software for desktop applications, 
I would say that shipping without the assertions may be the wrong engineering decision, 
but it is most definitely the correct business decision. 
Remember, shipping with the assertions enabled will not make the software any more robust. 
In fact, it can have the opposite effect. 
In many cases a program will exit when it hits an assert, but had it continued running, 
the effect of the bug might not have been noticed by the user. 
You don't want this to happen in a nuclear power plant, 
but someone running a word processor may not care that one line was misaligned during a screen refresh routine. 
Perception of the product will be based far more on the number of crashes than any other inconsistencies. 
You must also allow for the small percentage of assertions that will actually be checking the wrong expression. 
The condition they check may just be a bit stricter than was necessary. 
They may not have fired in testing, but they might fire in the field where a broader range of input is present.

The other thing to consider is what will be done with the assertion information once it is displayed to the user. 
The people at Microsoft have a lot of bugs to fix, they have plenty of data on where those bugs are, and, 
like any other desktop software company, they will choose to fix some and not others, putting any surplus effort into developing new functionality. 
The extra information gathered in the field from assertions firing would probably never be put to much use, 
and certainly not enough to compensate for the increase in size and decrease in speed of the product.

Away from desktop office applications, the parameters are different. 
In some cases, a company will have a small number of high-value customers, 
and it may be vital to fully investigate any failures that occur at those customers' sites.

Many embedded systems are capable of restarting themselves, 
which is often a reasonable option when an assertion fails. 
Like most developers working with desktop systems, it was probably not an option for Maguire.

Another reason for keeping asserts in the ship version of an embedded product is 
that turning the asserts off will change the timing characteristics of the program. 
On a desktop application, this rarely leads to a different end result. 
In real-time applications, 
removing the asserts may lead to misbehavior that did not arise before—and the assertions will not be in place to detect the situation. 
It's also worth bearing in mind that on the desktop, more speed is always better, 
while on embedded products, extra speed is often not an advantage, once you meet your hard real-time targets.

In Assert Yourself(link is external), we will look at how the assert() 
macro is written and which parts of it you may want to tune to fit the needs of your own project. 
If you are bug-hunting in the meantime, stop and consider whether a well-placed assertion could have saved you some time.
