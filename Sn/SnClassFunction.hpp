#ifndef _SnClassFunction
#define _SnClassFunction

#include "RtensorObj.hpp"


namespace Snob2{

  class SnClassFunction: public cnine::RtensorObj{
  public:

    typedef cnine::RtensorObj rtensor;

    using rtensor::rtensor;

    int n;

    template<typename FILLTYPE, typename = typename std::enable_if<std::is_base_of<cnine::fill_pattern, FILLTYPE>::value, FILLTYPE>::type>
    SnClassFunction(int _n, const FILLTYPE& fill, const int _dev=0):
      rtensor({_snbank->get_Sn(_n)->ncclasses()},fill,_dev), n(_n){}


    
  public: // ---- Named constructors ------------------------------------------------------------------------


    SnClassFunction static raw(const int n, const int _dev=0){
      return SnClassFunction(n,cnine::fill_raw(),_dev);}

    SnClassFunction static zero(const int n, const int _dev=0){
      return SnClassFunction(n,cnine::fill_zero(),_dev);}

    SnClassFunction static gaussian(const int n, const int _dev=0){
      return SnClassFunction(n,cnine::fill_gaussian(),_dev);}



  public: // ---- Access ------------------------------------------------------------------------------------


    float operator()(const IntegerPartition& lambda){
      return rtensor::get_value(_snbank->get_Sn(lambda.getn())->index(lambda));
    }

    void set_value(const IntegerPartition& lambda, const float v){
      rtensor::set_value(_snbank->get_Sn(lambda.getn())->index(lambda),v);
    }
    

  public: // ---- I/O --------------------------------------------------------------------------------------- 


    string str(const string indent="") const{
      ostringstream oss;
      SnObj* Gobj=_snbank->get_Sn(n);
      for(int i=0; i<dims(0); i++){
	oss<<Gobj->cclass(i)<<" : ";
	oss<<RtensorObj::get_value(i)<<endl;
      }
      return oss.str();
    }

    friend ostream& operator<<(ostream& stream, const SnClassFunction& x){
      stream<<x.str(); return stream;
    }

  };

}

#endif
