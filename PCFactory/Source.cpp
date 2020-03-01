#include <iostream>
#include <string>

using namespace std;

class Box : public PCFactory {
	string color;
public:
	Box() { color = "black"; }
	Box(string colorBox) { color = colorBox;  }
};
class Processor : public PCFactory {
	string Ghz, core, flow;
public:
	Processor() { Ghz = "2.70", core = "4", flow = "4"; }
	Processor(string pGhz,string pCore,string pFlow) { Ghz = pGhz; core = pCore; flow = pFlow; }
};
class MatherBoard : public PCFactory {};
class Hdd : public PCFactory {};
class Memory : public PCFactory {};


class PC
{
	Box* box;
	Processor* processor;
	MatherBoard* matherBoard;
	Hdd* hdd;
	Memory* memory;
public:
	PC() {
		box = NULL;
		processor = NULL;
		matherBoard = NULL;
		hdd = NULL;
		memory = NULL;
	};
	virtual ~PC() {
		if (box) delete box;
		if (processor) delete processor;
		if (matherBoard) delete matherBoard;
		if (hdd) delete hdd;
		if (memory)	delete memory;
	};
	void info() {
		cout << endl << "Box: " << box;
		cout << endl << "Processor: " << processor;
		cout << endl << "MatherBoard: " << matherBoard;
		cout << endl << "Hdd: " << hdd;
		cout << endl << "Memory: " << memory;
	};
	Box* GetBox() { return box; }
	void SetBox(Box* pBox) { box = pBox; }

	Processor* GetProcessor() {	return processor; }
	void SetProcessor(Processor* pProcessor) { processor = pProcessor; }

	MatherBoard* GetMatherBoard() {	return matherBoard; }
	void SetMatherBoard(MatherBoard* pMatherBoard) { matherBoard = pMatherBoard; }

	Hdd* GetHdd() {	return hdd;	}
	void SetHdd(Hdd* pHdd) { hdd = pHdd; }

	Memory* GetMemory() { return memory; }
	void SetMemory(Memory* pMemory) { memory = pMemory; }
};

class PCFactory 
{
public:
	virtual Box* CreateBox() = 0;
	virtual Processor* CreateProcessor() = 0;
	virtual MatherBoard* CreateMatherBoard() = 0;
	virtual Hdd* CreateHdd() = 0;
	virtual Memory* CreateMemory() = 0;
};

class HomePCFactory : PCFactory
{
public:
	Box* CreateBox() { Box* BlackBox; return BlackBox; }
	Processor* CreateProcessor() { Processor* IntelCPU; return IntelCPU; }
	MatherBoard* CreateMatherBoard() { MatherBoard* GigabiteMatherboard; return GigabiteMatherboard; }
	Hdd* CreateHdd() { Hdd* Kingson; return Kingson; }
	Memory* CreateMemory() { Memory* Razen; return Razen; }
	};

class OfficePCFactory : PCFactory {
public:
	Box* CreateBox() { Box* LightBox; return LightBox; }
	Processor* CreateProcessor() { Processor* amdCPU; return amdCPU; }
	MatherBoard* CreateMatherBoard() { MatherBoard* AsusMatherboard; return AsusMatherboard; }
	Hdd* CreateHdd() { Hdd* Samsung; return Samsung; }
	Memory* CreateMemory() { Memory* Razen; return Razen; }
};

class PCConfiguration {
	PCFactory* pcFactory;
public:
	PCConfiguration() { pcFactory = NULL; }
	virtual ~PCConfiguration() { if (pcFactory) delete pcFactory; }
	PCFactory* GetPCFactory() { return pcFactory; }
	void SetPCFactory(PCFactory* pcCurrentFactory) { pcFactory = pcCurrentFactory; }

	void Configure(PC* pc) {
		pc->SetBox(pcFactory->CreateBox());
		pc->SetMatherBoard(pcFactory->CreateMatherBoard());
		pc->SetHdd(pcFactory->CreateHdd());
		pc->SetMemory(pcFactory->CreateMemory());
		pc->SetProcessor(pcFactory->CreateProcessor());
	}
};
	
int main() {
	PC
	
	

	cout << endl;
	system("pause");
	return 0;
}