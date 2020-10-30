#include "Matrix.h"
#include <iostream>
//#include <string>
using namespace std;


bool testForFileName(char *param){
  int i = 0;
  int length;
  while(param[i] != '\0'){
    i++;
  }
  length = i;
  if(length < 5){
    return false;
  } else {
    std::string str(param);
    string ext = str.substr(length-4,length);
    if(ext == ".txt"){
      return true;
    } else {
      return false;
    }
  }
}
bool testForOp(char *param){
  int i = 0;
  int length;
  while(param[i] != '\0'){
    i++;
  }
  length = i;
  if(length == 1){
    if(param[0] == 'x' || param[0] == '+'){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }


}
bool testForScalar(char *param){
  bool invalid = false;
  int i = 0;
  while(param[i] != '\0'){
    if(!isdigit(param[i])){
      invalid = true;
    }
    i++;
  }
  return !invalid;
}

int main(int argc, char **argv){
  Matrix x = Matrix();
  Matrix y = Matrix();
  int scalar;
  bool scalarOp = false;
  if(argc < 5){
    printf("Not enough inputs\n");
    return -1;
  }

  //printf(testForFileName(argv[1]) ? "true" : "false");
  if(testForFileName(argv[1])){
    if(x.fill_from_file(argv[1]) == -1){
      printf("File not found\n");
      return -1;
    }
    if(testForOp(argv[2])){
      if(testForScalar(argv[3])){
        scalarOp = true;
        scalar = atoi(argv[3]);
      } else if (testForFileName(argv[3])){
        if(y.fill_from_file(argv[3]) == -1){
          printf("File not found\n");
          return -1;
        }

      } else {
        printf("Malformed input\n");
        return -1;
      }
    } else {
      printf("Malformed input\n");
      return -1;
    }
  } else {
    printf("Malformed input\n");
    return -1;
  }
  if(testForFileName(argv[4])==false){
    printf("Malformed input\n");
    return -1;
  }
  if(scalarOp){
    if(argv[2][0] == '+'){
      x.add(scalar);
    } else if(argv[2][0] == 'x'){
      x.mult(scalar);
    } else {
      printf("Malformed input\n");
      return -1;
    }
    if(x.store_in_file(argv[4]) == -1){
      printf("File not found\n");
      return -1;
    }
    return 0;
  } else {
    if(argv[2][0] == 'x'){
      if(x.mult(&y) == -1){
        printf("Invalid matrix operation\n");
        return -1;
      } else {
        if(x.store_in_file(argv[4])==-1){
          printf("File not found\n");
          return -1;
        } else {
          return 0;
        }
        return 0;
      }
    } else if (argv[2][0] == '+'){
      if(x.add(&y) == -1){
        printf("Invalid matrix operation\n");
        return -1;
      } else {
        if(x.store_in_file(argv[4])==-1){
          printf("File not found\n");
          return -1;
        } else {
          return 0;
        }
      }
    } else {
      printf("Invalid operation\n");
      return -1;
    }
  }
}


































//
