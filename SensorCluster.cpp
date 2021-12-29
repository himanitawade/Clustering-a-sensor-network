#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "SensorCluster.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int nic) {

    return (nic / 100000 % 10);
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int nic) {

  return (nic / 10000 % 10);

}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int nic) {

  return (nic / 1000 % 10);

}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int nic) {
   // TODO: implement this function, then delete the return statement below
   return (nic / 100 % 10);
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int nic) {
    // TODO: implement this function, then delete the return statement below
    return (nic / 10 % 10);
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int nic) {
    // TODO: implement this function, then delete the return statement below
    return (nic / 1 % 10);
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int nic):itemName_(itemName), nic_(nic)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void SensorNIC::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int nic;
    while (myfile >> itemName >> nic) {
			if (itemName.size() > 0)
      	addItem(itemName, nic);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void SensorNIC::addItem(string itemName, unsigned int nic) {
  // function that adds the specified NIC to the sensor network (i.e., to all hash tables)
  Item item = Item(itemName,nic);

  hT1.insert({nic, item});
  hT2.insert({nic, item});
  hT3.insert({nic, item});
  hT4.insert({nic, item});
  hT5.insert({nic, item});
  hT6.insert({nic, item});

}

bool SensorNIC::removeItem(unsigned int nic) {
   // TODO: implement this function, then delete the return statement below

  // function that removes the sensor specified by the nic value from the network
  // if sensor is found, then it is removed and the function returns true
  // else returns false
  if (hT1.find(nic) != hT1.end())
  {
    hT1.erase(nic);
    hT2.erase(nic);
    hT3.erase(nic);
    hT4.erase(nic);
    hT5.erase(nic);
    hT6.erase(nic);

    return true;
  }

  else
    return false;

//   bool result = true;
//   hT1.erase(hT1.find(nic));
//   hT2.erase(hT2.find(nic));
//   hT3.erase(hT3.find(nic));
//   hT4.erase(hT4.find(nic));
//   hT5.erase(hT5.find(nic));
//   hT6.erase(hT6.find(nic));
//   return result;
}

unsigned int SensorNIC::bestHashing() {
  // TODO: implement this function, then delete the return statement below

  // function that decides the best hash function, i.e. the ones among
  // fct1-fct6 that creates the most balanced sensor network for the current
  // set of NIC addresses, i.e. data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

  // unsigned int balance[7];
  // balance[0] = 0;
  // unsigned int min_loc, max_loc;
  // min_loc = hT1.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT1.bucket_size(i))
  //     min_loc = hT1.bucket_size(i);
  //   else if (max_loc <= hT1.bucket_size(i))
  //     max_loc = hT1.bucket_size(i);
  // }
  // balance[1] = max_loc - min_loc;
  // min_loc = hT2.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT2.bucket_size(i))
  //     min_loc = hT2.bucket_size(i);
  //   else if (max_loc <= hT2.bucket_size(i))
  //     max_loc = hT2.bucket_size(i);
  // }
  // balance[2] = max_loc - min_loc;
  // min_loc = hT3.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT3.bucket_size(i))
  //     min_loc = hT3.bucket_size(i);
  //   else if (max_loc <= hT3.bucket_size(i))
  //     max_loc = hT3.bucket_size(i);
  // }
  // balance[3] = max_loc - min_loc;
  // min_loc = hT4.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT4.bucket_size(i))
  //     min_loc = hT4.bucket_size(i);
  //   else if (max_loc <= hT4.bucket_size(i))
  //     max_loc = hT4.bucket_size(i);
  // }
  // balance[4] = max_loc - min_loc;
  // min_loc = hT5.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT5.bucket_size(i))
  //     min_loc = hT5.bucket_size(i);
  //   else if (max_loc <= hT5.bucket_size(i))
  //     max_loc = hT5.bucket_size(i);
  // }
  // balance[5] = max_loc - min_loc;
  // min_loc = hT6.bucket_size(0);
  //
  // for (unsigned i=1; i<10; ++i) {
  //   if (min_loc >= hT6.bucket_size(i))
  //     min_loc = hT6.bucket_size(i);
  //   else if (max_loc <= hT6.bucket_size(i))
  //     max_loc = hT6.bucket_size(i);
  // }
  // balance[6] = max_loc - min_loc;
  // unsigned int temp = balance[1];
  // for (int i = 2; i < 7; i++){
  //   if (temp > balance[i]){
  //     temp = balance[i];
  //     min_loc = i;
  //   }
  // }
  // return min_loc;

  unsigned int min = hT1.bucket_size(0);
  unsigned int max = hT1.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT1.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best1 = max - min;

  min = hT2.bucket_size(0);
  max = hT2.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT2.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best2 = max - min;

  min = hT3.bucket_size(0);
  max = hT3.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT3.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best3 = max - min;

  min = hT4.bucket_size(0);
  max = hT4.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT4.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best4 = max - min;

  min = hT5.bucket_size(0);
  max = hT5.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT5.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best5 = max - min;

  min = hT6.bucket_size(0);
  max = hT6.bucket_size(0);
  for (auto i = 1; i < 10; ++i){
    unsigned int bucket = hT6.bucket_size(i);
    if (bucket < min){
      min = bucket;
    } else if (bucket > max){
      max = bucket;
    }
  }
  unsigned int best6 = max - min;
  unsigned int array[6] = {best1,best2,best3,best4,best5,best6};
  unsigned int minimum = array[0];
  for (int i = 0; i <= 5; i++){
    if (array[i] <= minimum){
      if (i != 5){
        minimum = array[i];
      } else {
        minimum = array[i];
        cout << minimum << endl;
      }
    }
  }

  for (int i = 1; i <= 6; i++){
    if (minimum == best1){
      return 1;
    } else if (minimum == best2){
      return 2;
    } else if (minimum == best3){
      return 3;
    } else if (minimum == best4){
      return 4;
    } else if (minimum == best5){
      return 5;
    } else if (minimum == best6){
      return 6;
    }
  }

  return 0;	
}

// ALREADY COMPLETED
size_t SensorNIC::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");

	return hT1.size();
}
