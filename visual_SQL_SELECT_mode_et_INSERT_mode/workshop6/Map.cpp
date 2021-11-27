#include "pch.h"
#include "Map.h"

System::String^ compMappage::Map::Select(void)
{
	return "SELECT Client.code_client, Personne.nom_personne, Personne.prenom_personne, Client.date_naissance, Client.numero_service_client, Client.activite_client FROM Client INNER JOIN Personne ON Personne.idPersonne = Client.idPersonne ;";
}



System::String^ compMappage::Map::Insert(void)
{
	return "INSERT INTO Personne(nom_personne, prenom_personne) VALUES('" + this->nom + "', '" + this->prenom + "'); INSERT INTO Client(numero_service_client, date_naissance, activite_client, idPersonne) VALUES('" + this->numService + "', '" + this->dateNaissance + "', '" + this->activiteClient + "', (SELECT idPersonne FROM Personne WHERE convert(varchar, nom_personne) = '" + this->nom + "' AND convert(varchar, prenom_personne) = '" + this->prenom + "'));";
}




System::String^ compMappage::Map::Delete(void)
{
	return "DELETE FROM Personne WHERE nom = '" + this->nom + "', prenom = '" + this->prenom + "';";
}
System::String^ compMappage::Map::Update(void)
{
	return "";
}
void compMappage::Map::setId(int Id)
{
	this->Id = Id;
}
void compMappage::Map::setNom(System::String^ nom)
{
	this->nom = nom;
}
void compMappage::Map::setPrenom(System::String^ prenom)
{
	this->prenom = prenom;
}
void compMappage::Map::setDateNaissance(System::DateTime^ dateNaissance) {
	this->dateNaissance = dateNaissance;
}
int compMappage::Map::getId(void) { return this->Id; }
System::String^ compMappage::Map::getNom(void) { return this->nom; }
System::String^ compMappage::Map::getPrenom(void) { return this->prenom; }