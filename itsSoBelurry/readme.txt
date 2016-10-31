Prelab Questions:

1. Padding Design:
   To hold any kernel between 3 - 11 pixels long, you would need a 306 x 306
   size array for handling any 256 x 256 image. The initial pixel of the 
   image would be placed at (5,5) of the padded array.
2. Kernel Design:

Raw Gaussian Kernel Values:

	0.778801 0.882497 0.778801 
	--------------------------
	0.882497     1    0.882497 
	--------------------------
	0.778801 0.882497 0.778801 
 

Normalized Gaussian Kernel Values:

   	0.101868 0.115432 0.101868 
	--------------------------
	0.115432 0.130801 0.115432 
	--------------------------
	0.101868 0.115432 0.101868

3. Varying Sigma and N:
	
	Increasing both Sigma and N increases the amount of blurring that happens. However, N has a more pronounced effect, since it draws on a greater number of pixels. 

4. What the Sobel Filter does:
	
	The sobel filter highlights edges of objects in an image, basically constructing an outline of the image.

5. Are sharp and blur inverses of each other?

	Unfortunately, sharp and blur are not inverse operations of each other. This is because sharpen works by highlighting illuminated edges and sections of the images, and leaving the rest blurred, and so it does not in fact sharpen the whole image, and therefore, will not reverse blur. Similarly, the converse isn't true.

6. How many operations does this program take?
	
	Since the kernel acts on every pixel, it will take 256 x 256 operations and at each pixel, it takes N squared operations to run the kernel. Therefore, the equation that approximates the number of operations is [ total(N) = 256 x 256 x N x N ].

