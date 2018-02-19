#ifndef DATE_H
#define DATE_H

class Date{
   private:
      int month;
      int day;
      int year;
   public:
      Date();
      Date(const int, const int, const int);
      void print_month(int) const;
      bool check_date(int, int) const;
      void format1(int, int, int) const;
      void format2(int, int, int) const;
      void format3(int, int, int) const;
};

#endif
