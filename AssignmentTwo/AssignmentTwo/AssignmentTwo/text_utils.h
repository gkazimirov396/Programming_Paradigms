#pragma once

class Line {
public:
    Line(const char* text = "");
    ~Line();
    const char* getText() const;
    void appendText(const char* text);
    void insertText(int charIndex, const char* text);

    Line* next;

private:
    char* text;
    void setText(const char* newText);
};

class TextEditor {
public:
    TextEditor();
    ~TextEditor();
    void appendText(const char* text);
    void startNewLine();
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    void printCurrentText() const;
    void insertText(int lineNumber, int charIndex, const char* text);
    void searchText(const char* query) const;
    void clearText();

private:
    struct Line {
        char* text;
        Line* next;
    };
    Line* head;

    void removeNewline(char* str) const;
};
