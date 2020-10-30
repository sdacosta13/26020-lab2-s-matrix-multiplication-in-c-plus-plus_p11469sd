#include "Matrix.h"
#include <fstream>
#include <iostream>
using namespace std;

Matrix::Matrix(){
  vector<vector<int>> _matrix;
}
int Matrix::rows(){
  return _matrix.size();
}
int Matrix::columns(){
  if(_matrix.empty()){
    return 0;
  } else {
    return _matrix[0].size();
  }
}
int Matrix::fill_from_file(char *path){
  string line;
  ifstream file1(path);
  vector<string> lines;
  if(file1.is_open()){
    while(getline(file1, line)){
      lines.push_back(line);
    }
    file1.close();
  } else {
    return -1;
  }


  for(long unsigned int i = 0; i < lines.size(); i++){
    _matrix.push_back(vector<int>());
    string num = "";
    for(long unsigned int j = 0; j < lines.at(i).length(); j++){
      if(isdigit(lines.at(i)[j])){
        num += lines.at(i)[j];
      } else {
        int new1 = stoi(num);
        _matrix.at(i).push_back(new1);
        num = "";
      }
    }
    int new1 = stoi(num);
    _matrix.at(i).push_back(new1);
    num = "";
  }
  return 0;
}
int Matrix::index(int row, int column){
  return _matrix.at(row).at(column);
}
void Matrix::print(){
  for(int i = 0; i <  Matrix::rows(); i++){
    for(int j = 0; j < Matrix::columns(); j++){
      printf("%d ",Matrix::index(i,j));
    }
    printf("\n");
  }
}
int Matrix::store_in_file(char *path){
  ofstream file1(path);
  std::string s;
  if(file1.is_open()){
    for(int i = 0; i <  Matrix::rows(); i++){
      for(int j = 0; j < Matrix::columns(); j++){
        s = std::to_string(Matrix::index(i,j));
        file1 << s;
        if(j+1 == Matrix::columns()){
          continue;
        } else {
          file1 << " ";
        }
      }
      file1 << "\n";
    }
    file1.close();
    return 0;
  } else {
    return -1;
  }

}
int Matrix::mult(int val){
  for(int i = 0; i <  Matrix::rows(); i++){
    for(int j = 0; j < Matrix::columns(); j++){
      _matrix.at(i).at(j) *= val;
    }
  }
  return 0;
}
int Matrix::add(int val){
  for(int i = 0; i <  Matrix::rows(); i++){
    for(int j = 0; j < Matrix::columns(); j++){
      _matrix.at(i).at(j) += val;
    }
  }
  return 0;
}

int Matrix::add(Matrix *m){
  if((Matrix::rows() == m->rows()) && (Matrix::columns() == m->columns())) {
    for(int i = 0; i <  Matrix::rows(); i++){
      for(int j = 0; j < Matrix::columns(); j++){
        _matrix.at(i).at(j) += m->index(i,j);
      }
    }
    return 0;
  } else {
    return -1;
  }
}
int Matrix::mult(Matrix *m){
  if(Matrix::columns() == m->rows()){
    vector<vector<int>> newMat( Matrix::rows() , vector<int> (m->columns()));
    for(int i = 0; i < Matrix::rows(); i++){
      for(int j = 0; j < m->columns(); j++){
        for(int k = 0; k < m->rows(); k++){
          newMat.at(i).at(j) += Matrix::index(i,k) * m->index(k,j);
        }
      }
    }
    Matrix::_matrix = newMat;
    return 0;
  } else {
    return -1;
  }
}



































//
