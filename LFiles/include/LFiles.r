/* Standard Get Folder */

/* Yes! These are the Rez definitions for StandardGetFolder!!! */

resource 'DLOG' (2008, "CustomGet-Select Directory", purgeable) {
	{0, 0, 226, 344},
	noGrowDocProc,
	invisible,
	noGoAway,
	0x0,
	2008,
	"",
	alertPositionMainScreen
};

resource 'DITL' (2008, "CustomGet-Select Directory", purgeable) {
	{	/* array DITLarray: 12 elements */
		/* [1] */
		{159, 252, 179, 332},
		Button {
			enabled,
			"Open"
		},
		/* [2] */
		{128, 252, 148, 332},
		Button {
			enabled,
			"Cancel"
		},
		/* [3] */
		{-1, -1, -1, -1},
		HelpItem {
			disabled,
			HMScanhdlg {
				-6042
			}
		},
		/* [4] */
		{32, 235, 48, 337},
		UserItem {
			enabled
		},
		/* [5] */
		{56, 252, 76, 332},
		Button {
			enabled,
			"Eject"
		},
		/* [6] */
		{84, 252, 104, 332},
		Button {
			enabled,
			"Desktop"
		},
		/* [7] */
		{53, 12, 183, 230},
		UserItem {
			enabled
		},
		/* [8] */
		{31, 12, 50, 230},
		UserItem {
			enabled
		},
		/* [9] */
		{115, 251, 116, 333},
		Picture {
			disabled,
			11
		},
		/* [10] */
		{199, 35, 217, 210},
		Button {
			enabled,
			""
		},
		/* [11] */
		{7, 15, 23, 229},
		StaticText {
			disabled,
			""
		},
		/* [12] */
		{-1, -1, -1, -1},
		StaticText {
			disabled,
			"Select ^0"
		}
	}
};

resource 'dctb' (2008) {
	{	/* array ColorSpec: 1 elements */
		/* [1] */
		wContentColor, 56797, 56797, 56797
	}
};
