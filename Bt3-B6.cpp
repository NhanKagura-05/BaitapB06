#include <iostream>
#include <string>
#include <vector>

class Account {
    protected:
    std::string accountNumber;
    std::string ownerName;
    double balance;

    public:
    Account(std::string number, std::string name, double initialBalance)
    : accountNumber(number), ownerName(name), balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Đã nạp " << amount << " vào tài khoản. " << std::endl; 
        } else {
            std::cout << "Số tiền không hợp lệ. " << std::endl;
        }
    }
    virtual bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Đã rút " << amount << " từ tài khoản." << std::endl;
            return true;
        } else {
            std::cout << "Không thể rút tiền. Số dư không đủ hoặc số tiền không hợp lệ. " << std::endl;
            return false;
        }
    }
    virtual void displayInfo() const {
        std::cout << "Số tài khoản: " << accountNumber << std::endl;
        std::cout << "Chủ tài khoản: " << ownerName << std::endl;
        std::cout << "Số dư: " << balance << std::endl;
    }
    virtual ~Account() {}
};
class SavingsAccount : public Account {
    private:
    double interestRate;
    public:
    SavingsAccount(std::string number, std::string name, double initialBalance, double rate)
    : Account(number, name, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double Interest = balance * interestRate;
        deposit(Interest);
        std::cout << "Lãi suất: " << (interestRate * 100) << "%" << std::endl;
    }
};

class CheckingAccount : public Account {
    private:
    double overdraftLimit;

    public:
    CheckingAccount(std::string number, std::string name, double initialBalance, double limit)
    : Account(number, name, initialBalance), overdraftLimit(limit) {}

    bool withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            balance -= amount;
            std::cout << "Đã rút " << amount << " từ tài khoản." << std::endl;
            return true;
        } else {
            std::cout << "Không thể rút tiền. Vượt quá giới hạn thấu chi hoặc số tiền không hợp lệ. " << std::endl;
            return false;
        }
    }
void displayInfo() const override {
    Account::displayInfo();
    std::cout << "Giới hạn thấu chi: " << overdraftLimit << std::endl;
}
};

class Bank {
private:
std::vector<Account*> accounts;

public:
void addAccount(Account* account) {
    accounts.push_back(account);
}
void displayAllAccounts() const {
    for (const auto& account : accounts) {
        account->displayInfo();
        std::cout << "------------------------" << std::endl;
    }
}
~Bank() {
    for (auto account : accounts) {
        delete account;
    }
}
};

int main() {
    Bank myBank;
    myBank.addAccount(new SavingsAccount("S001", "Nguyen Van A", 1000000, 0.05));
    myBank.addAccount(new CheckingAccount("C001", "Tran Thi B", 2000000, 500000));

    std::cout << "Thông tin tất cả tài khoản: " <<std::endl;
    myBank.displayAllAccounts();
    return 0;
}