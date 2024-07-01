#include "SQLHighlighter.h"

namespace WidgetControlles {

SQLHighlighter::SQLHighlighter(QTextDocument* parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);

    const QStringList sqlKeywordPatterns = {
        QStringLiteral("\\bADD\\b"),
        QStringLiteral("\\bALTER\\b"),
        QStringLiteral("\\bALL\\b"),
        QStringLiteral("\\bAND\\b"),
        QStringLiteral("\\bANY\\b"),
        QStringLiteral("\\bAS\\b"),
        QStringLiteral("\\bASC\\b"),
        QStringLiteral("\\bBACKUP\\b"),
        QStringLiteral("\\bBETWEEN\\b"),
        QStringLiteral("\\bBY\\b"),
        QStringLiteral("\\bCASE\\b"),
        QStringLiteral("\\bCHECK\\b"),
        QStringLiteral("\\bCREATE\\b"),
        QStringLiteral("\\bCOLUMN\\b"),
        QStringLiteral("\\bREPLACE\\b"),
        QStringLiteral("\\bDEFAULT\\b"),
        QStringLiteral("\\bDELETE\\b"),
        QStringLiteral("\\bDESC\\b"),
        QStringLiteral("\\bDROP\\b"),
        QStringLiteral("\\bCONSTRAINT\\b"),
        QStringLiteral("\\bUNIQUE\\b"),
        QStringLiteral("\\bDATABASE\\b"),
        QStringLiteral("\\bDEFAULT\\b"),
        QStringLiteral("\\bINDEX\\b"),
        QStringLiteral("\\bVIEW\\b"),
        QStringLiteral("\\bEXEC\\b"),
        QStringLiteral("\\bEXISTS\\b"),
        QStringLiteral("\\bFOREIGN\\b"),
        QStringLiteral("\\bKEY\\b"),
        QStringLiteral("\\bFROM\\b"),
        QStringLiteral("\\bFULL\\b"),
        QStringLiteral("\\bGROUP\\b"),
        QStringLiteral("\\bHAVING\\b"),
        QStringLiteral("\\bIN\\b"),
        QStringLiteral("\\bINDEX\\b"),
        QStringLiteral("\\bINNER\\b"),
        QStringLiteral("\\bINSERT\\b"),
        QStringLiteral("\\bIS\\b"),
        QStringLiteral("\\bJOIN\\b"),
        QStringLiteral("\\bLEFT\\b"),
        QStringLiteral("\\bLIKE\\b"),
        QStringLiteral("\\bLIMIT\\b"),
        QStringLiteral("\\bNOT\\b"),
        QStringLiteral("\\bNULL\\b"),
        QStringLiteral("\\bOR\\b"),
        QStringLiteral("\\bORDER\\b"),
        QStringLiteral("\\bOUTER\\b"),
        QStringLiteral("\\bPRIMARY\\b"),
        QStringLiteral("\\bKEY\\b"),
        QStringLiteral("\\bPROCEDURE\\b"),
        QStringLiteral("\\bRIGHT\\b"),
        QStringLiteral("\\bJOIN\\b"),
        QStringLiteral("\\bROWNUM\\b"),
        QStringLiteral("\\bDISTINCT\\b"),
        QStringLiteral("\\bINTO\\b"),
        QStringLiteral("\\bTOP\\b"),
        QStringLiteral("\\bSELECT\\b"),
        QStringLiteral("\\bSET\\b"),
        QStringLiteral("\\bTABLE\\b"),
        QStringLiteral("\\bTOP\\b"),
        QStringLiteral("\\bTRUNCATE\\b"),
        QStringLiteral("\\bTABLE\\b"),
        QStringLiteral("\\bUNION\\b"),
        QStringLiteral("\\bUNIQUE\\b"),
        QStringLiteral("\\bUPDATE\\b"),
        QStringLiteral("\\bVALUES\\b"),
        QStringLiteral("\\bVIEW\\b"),
        QStringLiteral("\\bWHERE\\b")
    };

    // true false 0123456789
    QFont fontKeywordFormat;
    fontKeywordFormat.setFamily("Courier");
    fontKeywordFormat.setFixedPitch(true);
    fontKeywordFormat.setBold(true);
    fontKeywordFormat.setPointSize(14);

    for (const QString& pattern : sqlKeywordPatterns) {
        rule.pattern = QRegularExpression(pattern, QRegularExpression::CaseInsensitiveOption);
        rule.format = keywordFormat;
        rule.format.setFont(fontKeywordFormat);
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::green);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}

SQLHighlighter::~SQLHighlighter()
{

}

void SQLHighlighter::highlightBlock(const QString& text)
{
    for (const HighlightingRule& rule : std::as_const(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);

        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);

        int endIndex = match.capturedStart();
        int commentLength = 0;

        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }

        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

} // namespace WidgetControlles
