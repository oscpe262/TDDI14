/*
 * uppgift1.cc    TDDI14 2014-10-21
 */
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Grill
{
public:
   Grill(const Grill& other) = delete;
   virtual ~Grill() = 0;
   Grill& operator=(const Grill&) = delete;

   string get_model() const { return model_; }

protected:
   explicit Grill(const string& model) : model_(model) {}
      
private:
   const string model_;
};

Grill::~Grill() = default;

class Grill_Charcoal : public Grill
{
public:
   explicit Grill_Charcoal(const string& model) : Grill(model) {}

   Grill_Charcoal(const Grill_Charcoal& other)  = default;
   ~Grill_Charcoal() = default;
   Grill_Charcoal& operator=(const Grill_Charcoal&) = delete;
};

class Grill_LPG : public Grill
{
public:
   Grill_LPG(const string& model, 
	     int           n_burners, 
	     const string& lpg = "Propan")
      : Grill(model), n_burners_(n_burners), lpg_(lpg)
   {}

   Grill_LPG(const Grill_LPG& other) = delete;
   ~Grill_LPG() = default;
   Grill_LPG& operator=(const Grill_LPG&) = delete;

   int    get_burners() const { return n_burners_; }
   string get_lpg()     const { return lpg_; }

private:
   const int    n_burners_;
   const string lpg_;
};

class Grill_LPG_Sideburner : public Grill_LPG
{
public:
   Grill_LPG_Sideburner(const string& model, 
			int          n_burners, 
			const string& lpg = "Propan")
      : Grill_LPG(model, n_burners, lpg)
   {}

   Grill_LPG_Sideburner(const Grill_LPG_Sideburner& other) = delete;
   ~Grill_LPG_Sideburner() = default;
   Grill_LPG_Sideburner& operator=(const Grill_LPG_Sideburner&) = delete;
};

void print(const Grill* p)
{
   cout << "Grill " << p->get_model();

   if (typeid(*p) == typeid(Grill_LPG))
   {
      const Grill_LPG* lpg = dynamic_cast<const Grill_LPG*>(p);
      cout << ", " << lpg->get_burners()
	   << " brännare, " << lpg->get_lpg();
   }
   else if (typeid(*p) == typeid(Grill_LPG_Sideburner))
   {
      const Grill_LPG_Sideburner* lpgs = dynamic_cast<const Grill_LPG_Sideburner*>(p);
      cout << ", " << lpgs->get_burners()
	   << "+1 brännare, " << lpgs->get_lpg();
   }
   cout << endl;
}

int main()
{
   vector<Grill*> grills {
      new Grill_Charcoal("C-1900"),
      new Grill_LPG("LPG-4702", 2),
      new Grill_LPG_Sideburner("LPGS-4704", 4, "Butan")
   };

   for (auto& p : grills)
   {
      print(p);
      delete p;
      p = nullptr;
   }
   
   return 0;
}
