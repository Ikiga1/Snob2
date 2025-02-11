
// This file is part of Snob2, a symmetric group FFT library. 
// 
// Copyright (c) 2021, Imre Risi Kondor
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.


#ifndef _Snob2_base
#define _Snob2_base

#include "Cnine_base.hpp"

using namespace std; 
//using namespace Cnine; 


#define SNOB2_ASSERT(condition, message) if (!(condition)) {cout<<message<<endl; assert ((condition)); exit(-1); }

#define SNOB2_UNIMPL() printf("Snob2 error: function \"%s\" not implemented.\n",__PRETTY_FUNCTION__);

#define SNOB2_ERROR(cmd) {CoutLock lk; cerr<<"Snob2 error in function '"<<__PRETTY_FUNCTION__<<"' : "<<cmd<<endl;} exit(1);



namespace Snob2{

  inline ostream& operator<<(ostream& stream, const vector<int>& v){
    stream<<"(";
    for(int i=0; i<v.size()-1; i++)
      stream<<v[i]<<",";
    if(v.size()>0) stream<<v[v.size()-1]<<")";
    return stream;
  }


  template<typename TYPE>
  tuple<TYPE,TYPE,TYPE> order(const TYPE& x0, const TYPE& x1, const TYPE& x2){
    if(x0<x1){
      if(x1<x2) return tuple<TYPE,TYPE,TYPE>(x0,x1,x2);
      else{
	if(x0<x2) return tuple<TYPE,TYPE,TYPE>(x0,x2,x1);
	else return tuple<TYPE,TYPE,TYPE>(x2,x0,x1);
      }
    }else{
      if(x0<x2) return tuple<TYPE,TYPE,TYPE>(x1,x0,x2);
      else{
	if(x1<x2) return tuple<TYPE,TYPE,TYPE>(x1,x2,x0);
	else return tuple<TYPE,TYPE,TYPE>(x2,x0,x1);
      }
    }
    return tuple<TYPE,TYPE,TYPE>(x0,x1,x2);
  }

}






#endif 
