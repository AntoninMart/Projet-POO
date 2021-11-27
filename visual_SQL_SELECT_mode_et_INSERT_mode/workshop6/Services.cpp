#include "pch.h"
#include "Services.h"
#include "Personne.h"
using namespace System;

NS_Comp_Svc::CLservices::CLservices(void)
{
	this->oCad = gcnew compData::Cad();
	this->oMappTB = gcnew compMappage::Map();
}
System::Data::DataSet^ NS_Comp_Svc::CLservices::selectionnerToutesLesPersonnes(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}
System::Collections::ArrayList^ NS_Comp_Svc::CLservices::select()
{
	System::Data::DataSet^ ds = this->oCad->getRows(this->oMappTB->Select(), "a");

	System::Collections::ArrayList^ l = gcnew System::Collections::ArrayList();
	for (int i = 0;i < ds->Tables["a"]->Rows->Count;i++) {
		Personne^ p = gcnew Personne();
		p->codeClient = (int)ds->Tables["a"]->Rows[i]->ItemArray[0];
		p->nom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[1];
		p->prenom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[2];
		p->dateNaissance = (DateTime^) ds->Tables["a"]->Rows[i]->ItemArray[3];
		p->numService = (String^) ds->Tables["a"]->Rows[i]->ItemArray[4];
		p->activiteClient = (Boolean^) ds->Tables["a"]->Rows[i]->ItemArray[5];
		l->Add(p);
	}
	return l;
}
void NS_Comp_Svc::CLservices::update(Personne^ p) {
	this->oCad->actionRows("UPDATE Personne SET nom = '" + p->nom + "' WHERE id = "+p->codeClient);
}
void NS_Comp_Svc::CLservices::ajouterUnClient(System::String^ nom, System::String^ prenom, System::DateTime^ dateNaissance)
{
	System::String^ sql;

	this->oMappTB->setNom(nom);
	this->oMappTB->setPrenom(prenom);
	this->oMappTB->setDateNaissance(dateNaissance);
	sql = this->oMappTB->Insert();

	this->oCad->actionRows(sql);
}