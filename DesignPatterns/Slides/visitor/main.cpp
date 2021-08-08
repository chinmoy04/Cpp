#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


	using namespace std;

	class MyCAD;

	class graphics
	{
	public:
		// points
	};

	class filetype
	{
	public:
		virtual void save_it(MyCAD *p_CAD) = 0;
	};

	class MyCAD
	{
		vector<graphics *> objects;
	public:
		virtual void save_as(filetype *p_filetype)
		{
			p_filetype->save_it(this);
		}
	};


	class Afiletype : public filetype
	{
	public:
		virtual void save_it(MyCAD *p_CAD)
		{
			cout << "saved it as AfileType" << endl;
		}
	};

	class Bfiletype : public filetype
	{
	public:
		virtual void save_it(MyCAD *p_CAD)
		{
			cout << "saved it as BfileType" << endl;
		}
	};


	int main(int argc, char* argv[])
	{
		Afiletype atype;
		Bfiletype btype;
		MyCAD cad;
		cad.save_as(&atype);
		cad.save_as(&btype);
	}


