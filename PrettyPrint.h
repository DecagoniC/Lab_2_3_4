#pragma once
#include <iostream>

class PrettyPrinter {
public:
    PrettyPrinter(const std::string& indent = "  ", const std::string& separator = ", ")
        : indent_(indent), separator_(separator) {
    }

    template<typename T>
    bool print(const T& item, std::ostream& os = std::cout) const {
        if (!os) return false;
        (*this)(item, os); // Используем operator()
        os << "\n";
        return true;
    }

    template<typename T>
    void operator()(const T& item, std::ostream& os = std::cout) const {
        os << item; // Будет использовать operator<< для типа T
    }

    PrettyPrinter setIndent(const std::string& indent) const {
        return PrettyPrinter(indent, separator_);
    }

    PrettyPrinter setSeparator(const std::string& separator) const {
        return PrettyPrinter(indent_, separator);
    }

    const std::string& getIndent() const { return indent_; }
    const std::string& getSeparator() const { return separator_; }

private:
    const std::string indent_;
    const std::string separator_;
};

static const PrettyPrinter prettyprinter;