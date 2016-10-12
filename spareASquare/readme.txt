
Number of Squares
Probability : Simulations : Result = 
10 : .5 : 100 = 3.36

10 : .5 : 1,000 = 3.527
10 : .5 : 1,000 =  3.423

10 : .5 : 10,000 = 3.5099
10 : .5 : 10,000 = 3.5253
10 : .5 : 10,000 = 3.537

10 : .5 : 100,000 = 3.51787
10 : .5 : 100,000 = 3.51417
10 : .5 : 100,000 = 3.51674

10 : .5 : 1,000,000 = 3.52071
10 : .5 : 1,000,000 = 3.51958
10 : .5 : 1,000,000 = 3.52015

10 : .5 : 2,000,000 = 3.52633
10 : .5 : 2,000,000 = 3.52459
10 : .5 : 2,000,000 = 3.52481

10 : .5 : 9,000,000 = 3.52374
10 : .5 : 9,000,000 = 3.52524
10 : .5 : 9,000,000 = 3.5243
While 10,000 trials, does sometimes yield highly accurate results, it is not
precise enough to yield consistent results, that is, the values it provides
vary too much to be reliable.

At 1,000,000 trials, your hundredths digit still varies, meaning that, while precise to the tenths place, it is still not reliable
when more precise approximations are needed. 

At 9,000,000 trials, the hundredths digit becomes constant, and the variance occurs on the order of thousandths, which is quite
accurate. For most things, this should be enough accuracy, only varying about .002, which is an acceptably small margin of error.
However, we may be able to accomplish similar accuracy wih fewer trials

At 2,000,000 trials, the hundredths digit is also constant, meaning that, again, the variance only occurs at the thousandths.
This means that our results for 2,000,000 trials is comparable to that of 9,000,000, and therefore, we don't need to
execute those additional 7,000,000 simulations, since our results are reasonably accurate at 2,000,000 simulations. 

In summary, the diminishing returns for a value accurate to 2 decimal values happens at around 2,000,000 simulations. 
