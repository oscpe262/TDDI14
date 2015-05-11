/*
 * uppgift1.cc    TDDI14 2014-05-28
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Washing_Equipment
{
public:
   virtual ~Washing_Equipment() = default;

   virtual Washing_Equipment* copy() const = 0;

   string get_model() const { return model_; }
   string get_energy_class() const { return energy_class_; }

protected:
   Washing_Equipment(const string& model, const string& energy_class)
      : model_{ model }, energy_class_{ energy_class }
   {}

   Washing_Equipment(const Washing_Equipment&) = default;
   Washing_Equipment(Washing_Equipment&&) = default;

private:
   Washing_Equipment& operator=(const Washing_Equipment&) = delete;
   
   const string model_;
   const string energy_class_;  // A+++, A++, A+, A, B, C
};

class Washing_Machine : public Washing_Equipment
{
public:
   Washing_Machine(const string& model, const string& energy_class,
		   float capacity, int max_spin)
      : Washing_Equipment{ model, energy_class }, capacity_{ capacity }, max_spin_{ max_spin }
   {}

   ~Washing_Machine() = default;

   Washing_Machine* copy() const override { return new Washing_Machine{ *this }; }

   float get_capacity() const { return capacity_; }
   int   get_max_spin() const { return max_spin_; }

protected:
   Washing_Machine(const Washing_Machine&) = default;
   Washing_Machine(Washing_Machine&&) = default;

private:
   Washing_Machine& operator=(const Washing_Machine&) = delete;

   const float capacity_;  // kg
   const int   max_spin_;  // rpm
};

class Clothes_Dryer : public Washing_Equipment
{
protected:
   Clothes_Dryer(const string& model, const string& energy_class)
      : Washing_Equipment{ model, energy_class }
   {}

   ~Clothes_Dryer() = default;

   Clothes_Dryer(const Clothes_Dryer&) = default;
   Clothes_Dryer(Clothes_Dryer&&) = default;

private:
   Clothes_Dryer& operator=(const Clothes_Dryer&) = delete;
};

class Condenser_Dryer : public Clothes_Dryer
{
public:
   Condenser_Dryer(const string& model, const string& energy_class, float capacity)
      : Clothes_Dryer{ model, energy_class }, capacity_{ capacity }
   {}

   ~Condenser_Dryer() = default;

   Condenser_Dryer* copy() const override { return new Condenser_Dryer{ *this }; }

   float get_capacity() const { return capacity_; }

protected:
   Condenser_Dryer(const Condenser_Dryer&) = default;
   Condenser_Dryer(Condenser_Dryer&&) = default;

private:
   Condenser_Dryer& operator=(const Condenser_Dryer&) = delete;

   const float capacity_;  // kg
};

class Tumble_Dryer : public Clothes_Dryer
{
public:
   Tumble_Dryer(const string& model, const string& energy_class)
      : Clothes_Dryer{ model, energy_class }
   {}

   ~Tumble_Dryer() = default;

   Tumble_Dryer* copy() const override { return new Tumble_Dryer{ *this }; }

protected:
   Tumble_Dryer(const Tumble_Dryer&) = default;
   Tumble_Dryer(Tumble_Dryer&&) = default;

private:
   Tumble_Dryer& operator=(const Tumble_Dryer&) = delete;
};

class Dish_Washer : public Washing_Equipment
{
public:
   Dish_Washer(const string& model, const string& energy_class, 
	       int capacity, int noise_level)
      : Washing_Equipment{ model, energy_class }, 
	capacity_{ capacity }, noise_level_{ noise_level }
   {}

   ~Dish_Washer() = default;

   Dish_Washer* copy() const override { return new Dish_Washer{ *this }; }

   int get_capacity() const { return capacity_; }
   int get_noise_level() const { return noise_level_; }

protected:
   Dish_Washer(const Dish_Washer&) = default;
   Dish_Washer(Dish_Washer&&) = default;

private:
   Dish_Washer& operator=(const Dish_Washer&) = delete;

   const int capacity_;     // number of settings
   const int noise_level_;  // dB
};

void print(const Washing_Equipment* p)
{
   // TODO: create a copy of the object the parameter p is pointing to
   Washing_Equipment* pc = p->copy();

   // print data from the copy
   cout << fixed << setprecision(2);

   const Washing_Machine* wm = dynamic_cast<const Washing_Machine*>(pc);
   const Condenser_Dryer* cd = dynamic_cast<const Condenser_Dryer*>(pc);
   const Tumble_Dryer*    td = dynamic_cast<const Tumble_Dryer*>(pc);
   const Dish_Washer*     dw = dynamic_cast<const Dish_Washer*>(pc);

   cout << pc->get_model();
   if (wm)
      cout << ", Washing machine: " << wm->get_capacity() << " kg, " << wm->get_max_spin() << " rpm, ";
   else if (cd)
      cout << ", Condenser dryer: " << cd->get_capacity() << " kg, ";
   else if (td)
      cout << ", Tumble dryer: ";
   else if (dw)
      cout << ", Dish washer: " << dw->get_capacity() << " settings, " << dw->get_noise_level() << " dB, ";
   cout << "energy class " << pc->get_energy_class() << '\n';
   
   delete pc;
}

int main()
{
   Washing_Equipment* p_washing_machine  = new Washing_Machine{ "WE1486WM", "A+", 8.0, 1400 };
   Washing_Equipment* p_condenser_dryer  = new Condenser_Dryer{ "WE6756CD", "B", 7.5 };
   Washing_Equipment* p_tumble_dryer     = new Tumble_Dryer{ "WE1809TD", "C" };
   Washing_Equipment* p_dish_washer      = new Dish_Washer{ "WE6570DW", "A", 12, 47 };

   print(p_washing_machine);
   print(p_tumble_dryer);
   print(p_condenser_dryer);
   print(p_dish_washer);

   delete p_washing_machine;
   delete p_condenser_dryer;
   delete p_tumble_dryer;
   delete p_dish_washer;

   return 0;
}
