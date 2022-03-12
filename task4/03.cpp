#include <iostream>

using namespace std;

class Material {

public:
	 //Принимает на вход величину деформации
	 //Возвращает величину напряженияб посчитанную с учётом реологии материала
	 virtual float getStress(float strain) = 0;
};

class ElasticMaterial : public Material {
public:
    ElasticMaterial(float elasticModulus)
    {
   		this->elasticModulus = elasticModulus;
   	}

   	float getStress(float strain) override
    {
   		return strain * this->elasticModulus;
   	}

private:
   	float elasticModulus;
};

class PlasticMaterial : public Material {
public:
   	PlasticMaterial(float elasticModulus, float strainLimit)
    {
   		this->elasticModulus = elasticModulus;
   		this->strainLimit = strainLimit;
   	}

   	float getStress(float strain) override
    {
   		if (strain < this->strainLimit)
   			return strain * this->elasticModulus;
   		return this->strainLimit * this->elasticModulus;
   	}

private:
   	float elasticModulus;
   	float strainLimit;
};

int main()
{
  Material* m;
  m = new ElasticMaterial(100);
  cout << "Material stress is: " << m->getStress(0.1) << endl;
  m = new PlasticMaterial(100, 0.01);
  cout << "Material stress is: " << m->getStress(0.1) << endl; 
}
