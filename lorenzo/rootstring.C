// extract to string
#include <iostream>
#include <string>

void rootstring(TString mystring = "102398.2039_upstream.root")
{

  if (mystring == "default_string"){
    cout << "Please, input string (no spaces):\t";
    cin >> mystring;
  }
  
  cout << "This is the string you input:\t" << mystring << endl;

  size_t pos;

  std::string search;
  search = "printer";
  pos = mystring.Index(search);

  if (pos != std::string::npos)
    std::cout << "string contains " << search << std::endl;
  else
    std::cout << "string does not contains " << search << std::endl;

  //get number
  if(mystring.Index("centred") != string::npos ){
    cout << "The resonance is centred. Adjust"<<endl;
  }
  else if(mystring.Index("_upstream") != string::npos ){
    cout << "The resonance is upstream. Adjust"<<endl;

    TString x = "This_is_a_string";
  // std::getline( mystring, token, "_");
    TObjArray *tx = mystring.Tokenize("_");
    

    Double_t value = ((TObjString *)(tx->At(0)))->String()->Atof();

    cout << "Value:\t" << value << "\nValue + 2:\t" << value+2 << endl;



  }
  else if(mystring.find("_downstream") != string::npos ){
    cout << "The resonance is downstream. Adjust"<<endl;
  }
  else{
    cout << "Please, check file name for correctness. Adjust" << endl;
  }


  //get down/upstream direction


}


