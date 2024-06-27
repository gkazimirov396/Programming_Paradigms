#ifndef TEXT_H
#define TEXT_H

class Text {
private:
    char* content;
    int length;

public:
    Text(const char* text, int len);
    ~Text();

    const char* getContent() const;
    int getLength() const;
    void setContent(const char* text, int len);
};

#endif // TEXT_H
