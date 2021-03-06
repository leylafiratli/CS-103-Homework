#include <iostream>
#include <fstream>

using namespace std;

void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Uncomment the line below for part 2
   sort(data, count);

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{

	int index = (start+end)/2;

	if(target == data[index]) {
		return index;
	}
	else if(start + 1 == end) {
		return -1;
	}
	else if(target > data[index]) {
		start = index;
	}
	else if(target < data[index]) {
		end = index;
	}
	return binsearch(target,data,start,end);
}
/*int main(int argc, char* argv[]) {
   
   // declare and take input
   double recipe_amounts[100];
   string recipe_items[100];
   int recipe_length;
   
   double store_prices[100];
   string store_items[100];
   int store_length;
   
   read(argv[1], &recipe_length, recipe_amounts, recipe_items);
   read(argv[2], &store_length, store_prices, store_items);

   bool impossible = false; // flag if some ingredient was missing
   double running_total = 0; // total cost
   
   for (int i=0; i<recipe_length; i++) {
      bool found_item = false; // do we find recipe item i?
      for (int j=0; j<store_length; j++) {
         if (recipe_items[i] == store_items[j]) { // found it!
            running_total += recipe_amounts[i] * store_prices[j];
            found_item = true;
         }         
      }
      if (!found_item) 
         impossible = true;
   }

   if (impossible)
      cout << "impossible" << endl;
   else
      cout << running_total << endl;

   return 0;
}*/


// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{

	if(len > 1) {
		int max = 0;
		int tempIndex;
		int temp = data[len-1];
		for(int i = 0; i < len; i ++) {
			 if(data[i] > max) {
			 	max = data[i];
			 	tempIndex = i;
			 }
		}
		data[tempIndex] = temp;
		data[len-1] = max;
		sort(data,len-1);
	}


}
