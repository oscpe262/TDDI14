/*
 * uppgift1.cc    TDDI14 2014-08-21
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <vector>
using namespace std;

class VC_Unit
{
public:
   virtual ~VC_Unit() = default;

   VC_Unit(const VC_Unit&) = delete;
   VC_Unit& operator=(const VC_Unit&) = delete;

   std::string get_manufacturer() const { return manufacturer_; }

   double get_price() const { return price_; }
   void   set_price(double price) { price_ = price; }

protected:
   explicit VC_Unit(const std::string& manufacturer, double price = 0.0) 
      : manufacturer_{ manufacturer }, price_{ price }
   {}

private:
   const std::string manufacturer_;
   double            price_;
};

class CA_Module : public VC_Unit
{
public:
   CA_Module(const std::string& manufacturer,
	     const std::string& ca_system, 
	     double             price = 0.0) 
      : VC_Unit{ manufacturer, price }, ca_system_{ ca_system }
   {}

   ~CA_Module() = default;

   CA_Module(const CA_Module&) = delete;
   CA_Module& operator=(const CA_Module&) = delete;

   std::string get_ca_system() const { return ca_system_; }

private:
   const std::string ca_system_;
};

class DTV_Box : public VC_Unit
{
public:
   DTV_Box(const std::string& manufacturer,
	   const std::string& model,
	   double             price = 0.0) 
      : VC_Unit{ manufacturer, price }, model_{ model }
   {}

   ~DTV_Box() = default;

   DTV_Box(const DTV_Box&) = delete;
   DTV_Box& operator=(const DTV_Box&) = delete;

   string get_model() const { return model_; }

private:
   const std::string model_;
};

class DTV_Box_Recordable : public DTV_Box
{
public:
   DTV_Box_Recordable(const std::string& manufacturer,
		      const std::string& model,
		      int                disk_size,
		      double             price = 0.0) 
      : DTV_Box{ manufacturer, model, price }, disk_size_{ disk_size }
   {}

   ~DTV_Box_Recordable() = default;

   DTV_Box_Recordable(const DTV_Box_Recordable&) = delete;
   DTV_Box_Recordable& operator=(const DTV_Box_Recordable&) = delete;

   int get_disk_size() const { return disk_size_; }

private:
   const int disk_size_;
};

void print(const VC_Unit& vc)
{
   cout << vc.get_manufacturer();

   if (typeid(vc) == typeid(CA_Module))
   {
      const CA_Module& ca = dynamic_cast<const CA_Module&>(vc);
      cout << " CA module, " << ca.get_ca_system() << ", ";
   }
   else if (typeid(vc) == typeid(DTV_Box))
   {
      const DTV_Box& dtv = dynamic_cast<const DTV_Box&>(vc);
      cout << " DTV box, " << dtv.get_model() << ", ";
   }
   else if (typeid(vc) == typeid(DTV_Box_Recordable))
   {
      const DTV_Box_Recordable& dtv_r = dynamic_cast<const DTV_Box_Recordable&>(vc);
      cout << " Recordable DTV Box, " << dtv_r.get_model() << ", " << dtv_r.get_disk_size() << "GB, ";
   }

   cout << fixed << setprecision(2) << vc.get_price() << " kr\n";
}

int main()
{
   CA_Module          ca{ "Dilog", "Viacess", 499.00 };
   DTV_Box            dtv{ "Samsung", "DTB-P850V", 2495.00 };
   DTV_Box_Recordable dtv_r{ "Samsung", "DTB-P770V PVR", 80, 2595.00 };

   print(ca);
   print(dtv);
   print(dtv_r);

   return 0;
}
