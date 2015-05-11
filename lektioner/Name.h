/*le2*/
#ifndef NAME_H
#define NAME_H

class Name {
public:
  Name(const std::string& fname) : fname_{fname} {}  
  Name(const Name& other) : fname_{other.fname_} {} //kop.konst
  Name(Name&& ) { swap(other); } //move.konst

  Name& operator=(const Name& rhs) & {
    Name{rhs}.swap(*this);
    return *this;
  }
  Name& operator=(const std::string& rhs) & {
    Name{rhs}.swap(*this);
    return *this;
  }
  Name& operator=(Name&& rhs) & {
    swap(rhs);
    return *this;
  }

  virtual void print(ostream& os);
  
  void swap(Name& other) noexcep;
private:
  std::string fname_:
};

class Double_Name : public Name {
public:
  Double_Name(const strig& fname, const string& sname) : Name(fname), sname_{sname} {};
  Double_Name(const Double_Name& other) : Name(other), sname_{other.sname_} {};
  Double_Name(Double_Name&& other) { swap(other); }

  Double_Name& operator=(const Double_Name& rhs) & {
    Double_Name{rhs}.swap(*this);
    return *this;
  }
  Double_Name& operator=(Double_Name&& rhs) & {
    swap(rhs);
    return *this;
  }

  virtual void print(ostream& os) override;
  
  void swap(Double_Name& other) noexcept;
    
private:
  std::string sname_;
}
#endif // NAME_H

