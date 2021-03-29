#define END 0

/* Pronoun conjugations. 
 * Ordered as: subject, object */
char *conjugations[] = {
    "ARE", "AM",
    "WERE", "WAS",
    "YOUR", "MY",
    "YOU", "I",
    "IVE", "YOUVE",
    "IM", "YOURE",
    END,
};

/* A mapping of keywords to their replies.
 * Ordered as: keyword, reply */
char *keyword_replies[] = {
    "CAN YOU", "DON'T YOU BELIVE I CAN %s",
    // TODO: Fill in.
    END,
};

/* I no keyword was found, use this reply. */
char no_keyword[] = "CAN YOU ELABORATE ON THAT";
