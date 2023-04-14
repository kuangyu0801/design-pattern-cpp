struct Document;

// struct IMachine
//{
//   virtual void Print(Document& doc) = 0;
//   virtual void Fax(Document& doc) = 0;
//   virtual void Scan(Document& doc) = 0;
// };
//
// struct MFP : IMachine
//{
//   void Print(Document& doc) override;
//   void Fax(Document& doc) override;
//   void Scan(Document& doc) override;
// };

// 1. Recompile
// 2. Client does not need this
// 3. Forcing implementors to implement too much

struct IPrinter {
  virtual void Print(Document& doc) = 0;
};

struct IScanner {
  virtual void Scan(Document& doc) = 0;
};

struct Printer : IPrinter {
  void Print(Document& doc) override;
};

struct Scanner : IScanner {
  void Scan(Document& doc) override;
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine {
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner)
      : printer{printer}, scanner{scanner} {}

  void Print(Document& doc) override { printer.Print(doc); }
  void Scan(Document& doc) override;
};

// IPrinter --> Printer
// everything --> Machine