#pragma once
#include "MapClient.h"
#include "Cad.h"

ref class Personne
{
public:
	int codeClient;
	System::String^ nom;
	System::String^ prenom;
	System::DateTime^ dateNaissance;
	System::String^ numService;
	System::Boolean^ activiteClient;

};

namespace NS_Comp_Svc
{
	ref class CLservices
	{
	private:
		compData::Cad^ oCad;
		compMappage::Map^ oMappTB;
	public:
		CLservices(void);
		System::Collections::ArrayList^ select();
		void update(Personne^ p);
		void ajouterUnClient(System::String^, System::String^, System::DateTime^);
	};
}