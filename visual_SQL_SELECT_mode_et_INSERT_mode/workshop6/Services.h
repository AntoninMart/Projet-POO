#pragma once
#include "Map.h"
#include "Cad.h"
#include "Personne.h"

namespace NS_Comp_Svc
{
	ref class CLservices
	{
	private:
		compData::Cad^ oCad;
		compMappage::Map^ oMappTB;
	public:
		CLservices(void);
		System::Data::DataSet^ selectionnerToutesLesPersonnes(System::String^);
		System::Collections::ArrayList^ select();
		void update(Personne^ p);
		void ajouterUnClient(System::String^, System::String^, System::DateTime^);
	};
}