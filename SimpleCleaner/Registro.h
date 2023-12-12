#pragma once
public ref class Registro
{
public:
	Registro();
	bool IsRunAsAdmin();
	bool Get_First_Use_status();

	void addDirectoryToRegistry(const char* directoryPath, bool standard);
	void Set_atual_index(int index);
	void Set_First_Use(bool IsFirst);
	void Delete_this_index(int index);
	void Set_Atual_delete(int index);

	int Get_Atual_Index();
	int Get_Atual_delete();
};

