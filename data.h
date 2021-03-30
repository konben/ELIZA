#define END 0

/* Pronoun conjugations. 
 * Ordered as: subject, object */
char *conjugations[] = {
    "ARE", "AM",
    "WERE", "WAS",
    "YOUR", "MY",
    //"YOU", "I",
    "IVE", "YOUVE",
    "IM", "YOURE",
    "ME", "YOU",
    "MYSELF", "YOURSELF",   
    END,
};

/* A mapping of keywords to their replies.
 * Ordered as: keyword, reply */
char *keyword_replies[] = {
    "CAN YOU", "DON'T YOU BELIVE I CAN %s?",
    "AFRAID OF", "AND WHY DO YOU THINK YOU ARE AFRAID OF %s?",
    "I FEEL", "WHY IS IT THAT YOU FEEL %s?",
    "I CAN'T FEEL", "WHY IS IT THAT YOU CAN'T FEEL %s?",
    "I LIKE", "AND WHY DO YOU LIKE %s?",
    "I DON'T LIKE", "AND WHY DO YOU NOT LIKE %s?",
    "I AM", "HOW DID YOU COME TO THE CONCLUSION THAT YOU ARE %s?",
    "I", "AND WHY IS IT THAT YOU %s?",
    "COMPUTER", "AND YOU DON'T BELIVE A COMPUTER CAN HELP YOU?",
    "FUCK", "LANGUAGE, PLEASE!",
    "F*CK", "LANGUAGE, PLEASE!",
    "HE", "AND WHAT DO YOU THINK ABOUT HIM?",
    "YOU", "THIS ISN'T ABOUT ME, ISN'T IT?",
    // TODO: Fill in.
    END,
};

/* I no keyword was found, use this reply. */
char no_keyword[] = "CAN YOU ELABORATE ON THAT?";
