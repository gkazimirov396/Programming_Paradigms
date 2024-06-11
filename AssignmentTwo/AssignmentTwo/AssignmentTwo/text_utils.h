#pragma once
#include <stack>

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
    void deleteText(int lineNumber, int charIndex, int numChars);
    void clearText();
    void undo();
    void redo();

private:
    struct Line {
        char* text;
        Line* next;
    };
    Line* head;

    std::stack<Line*> undoStack;
    std::stack<Line*> redoStack;

    void removeNewline(char* str) const;
    void saveState(std::stack<Line*>& stack);
    void restoreState(std::stack<Line*>& stack);
};
