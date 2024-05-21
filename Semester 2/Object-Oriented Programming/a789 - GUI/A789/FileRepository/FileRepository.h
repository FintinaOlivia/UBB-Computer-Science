//
// Created by Th on 30/05/2023.
//

#pragma once
#include "../Repository/repository.h"
#include "../Domain/domain.h"
#include <fstream>
#include <string>

class FileRepository: public Repository
{
public:
    explicit FileRepository(std::string file);

    const std::vector<Coat>& getArray() override;
    void AddRepo(const std::string& size, const std::string& color, int price, int quantity, std::string photograph);
    void DeleteEntireProductRepo(std::string size, std::string color, std::string photograph) override;
    void DeleteSoldOutProductRepo(std::string size, std::string color, std::string photograph) override;
    void UpdatePriceRepo(std::string size, std::string color, std::string photograph, int price) override;
    void UpdateQuantityRepo(std::string size, std::string color, std::string photograph, int quantity) override;
    int CheckExistenceCoat(std::string size, std::string color, std::string photograph) override;
    int GetSize() override;

private:
    std::string FileName;
//    Coat GetElement(int position);
//    vector<Coat> LoadData();
//    void WriteData( vector<Coat> Data);
    void LoadData();
    void WriteData();
};
