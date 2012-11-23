#include "NifExplorer.h"

void getInput( string & out )
{
	std::cout << "Please enter a block type name, with correct casing in the text!" << std::endl;

	std::cin >> out;

	if( out == "" || &out == NULL )
	{
		std::cout << "You need to enter a valid value." << std::endl;
	}

}

void getFile( string & out )
{
	std::cout << "Please enter a valid nif file to search!" << std::endl;

	std::cin >> out;

	if( !fopen(out.c_str(), "r"))
	{
		std::cout << "Nif file does not exist" << std::endl;
		getFile(out);
	}

	if( out == "" || &out == NULL )
	{
		std::cout << "Please enter a valid nif file!" << std::endl;
	}
}

void Delay( unsigned long ms )
{
	Sleep( ms );
}

int main()
{
	std::cout << "Using Nif Lib" << std::endl;

	string file;
	getFile(file);

	string  input;
	getInput(input);

	vector<Ref<NiObject>> objects = ReadNifList(file);

	for( int i = 0; i != objects.size(); ++i )
	{
		if( objects[i]->GetType().GetTypeName() == input )
		{
			std::cout << "Found '" << input << "' in '" << file << "'" << std::endl;
			Delay( 1000 * 5 );
			system("cls"); 
			main();
		}
		else
		{
			system("cls");
			main();
		}
	}
	

	system("pause");
	return 0;
}