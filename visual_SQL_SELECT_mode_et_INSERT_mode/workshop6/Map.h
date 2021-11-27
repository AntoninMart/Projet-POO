#pragma once
namespace compMappage
{
	ref class Map
	{
	private:
		System::String^ sSql;
		int Id;
		System::String^ nom;
		System::String^ prenom;
		System::DateTime^ dateNaissance;
		System::String^ numService = "06058654823";
		System::Boolean^ activiteClient = false;
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ Delete(void);
		System::String^ Update(void);
		void setId(int);
		void setNom(System::String^);
		void setPrenom(System::String^);
		void setDateNaissance(System::DateTime^);
		int getId(void);
		System::String^ getNom(void);
		System::String^ getPrenom(void);
	};
}