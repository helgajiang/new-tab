#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <boost/tokenizer.hpp>
using namespace std;

int main(){ 

    std::vector< vector <std::string> > colours;

    std::ifstream file("colours.txt");
    std::string str;
    int i = 0; 
  

    while (std::getline(file, str)){
      istringstream iss(str);
      string s;

      vector<std::string> row;
   

      while (getline(iss, s, '	')) {
        row.push_back(s);
//        cout << s << endl; 
      }
      colours.push_back(row);
      ++i;
//cout << "HEREE" << endl;

    }
//cout << "HEREE" << endl;

    file.close();
  //  cout << "HERE" <<endl;

    std::string result = "[";
    cout << colours.size() <<endl;
    for (int i=0; i<colours.size(); i++){
      result += "[\"";
      int difference = 0;
      if (colours[i].size() > 5){
         difference = colours[i].size() - 5;
      }
      for (int j=0; j<colours[i].size(); j++){
        if (j < difference){ //still on first 'string'
           result += "\"" + colours[i][j] + " ";
        }
        else if (j == colours[i].size()) { //last item in this array
           result += "\"" + colours[i][j] + "\"]";
        }
        else if (j == difference){
           result += colours[i][j] + "\", \"";
        }
        else if (j == colours[i].size()-1) {
           result += colours[i][j];
        }
        else {
           result += colours[i][j] + "\", \"";  
        }
      }
      result += "\"]";
      if (i != colours[i].size() && i != colours.size()-1){
        result += ", ";
      }
    }
    result += "]";
    cout << result << endl;
    
    std::ofstream out("colourArray.txt");
    out << result;
    out.close();


    for (int i=0; i<colours.size(); i++){
       colours[i].clear();
     }
    colours.clear();
}
