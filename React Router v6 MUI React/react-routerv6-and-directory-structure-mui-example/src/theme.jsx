import { createTheme, alpha } from '@mui/material/styles';
const colors = {
  primary: "#9E7676",
  secondary: "#FFF8EA",
  darkBlue: "#594545",
  gray: "#9194A2",
  bodyText: "rgba(32, 46, 69, 0.5)",
};
// A custom theme for this app
const theme = createTheme({
  palette: {
    primary: {
      light: '#FFF8EA',
      main: '#9E7676',
      dark: '#594545'
    },
    success: {
      light: '#E7F0DC',
      dark: '#059212',
      main: '#F3FF90'
    },
    error: {
      main: '#C70039',
      dark: '#900C3F'
    },
    warning: {
      main: '#FEFFD2',
      dark: '#FFDE55'
    },
    secondary: {
      main: '#f1c40f', // Yellow
      dark: '#FFC107',
      light: '#FFD700',
    },
    info: {
      main: '#2ecc71', // Green
    },
    background: {
      default: '#f0f0f0',
      paper: '#ffffff',
    },
    text: {
      primary: '#333333',
      secondary: '#666666',
    }
  },
  typography: {
    fontFamily: "Arial, sans-serif",
    fontSize: 16,

    h1: {
      fontSize: "1.875rem",
      lineHeight: "2.5rem",
      letterSpacing: "-0.095px",
      fontWeight: 500,
      color: colors.darkBlue,

      "@media (min-width: 1280px)": {
        fontSize: "3rem",
        lineHeight: "3.25rem",
      },
    },

    h2: {
      fontSize: "1.5rem",
      lineHeight: "3.25rem",
      fontWeight: 500,
      color: colors.darkBlue,

      "@media (min-width: 1280px)": {
        fontSize: "2rem",
        lineHeight: "3.25rem",
      },
    },

    h3: {
      fontSize: "1.25rem",
      lineHeight: "1.5rem",
      fontWeight: 500,
      color: colors.darkBlue,
    },

    body1: {
      fontSize: "0.9375rem",
      lineHeight: "1.5625rem",
      fontWeight: 400,
      color: colors.gray,

      "@media (min-width: 1280px)": {
        fontSize: "1.125rem",
        lineHeight: "1.75rem",
      },
    },
  },
  components: {
    MuiTextField: {
      styleOverrides: {
        root: {
          fontSize: 16,
          borderRadius: 8,
        },
      },
    },
    MuiButton: {
      styleOverrides: {
        root: {
          fontSize: "0.875rem",
          textTransform: "capitalize",

          paddingInline: "16px",
          paddingBlock: "10px",

          "@media (min-width:1024px)": {
            paddingInline: "24px",
          },

          border: "none",
          "&:hover": {
            border: "none",
          },
        },

        contained: {
          boxShadow: `0px 8px 8px -4px rgba(73, 93, 207, 0.20)`,

          border: "2px solid transparent",
          "&:hover": {
            backgroundColor: "white",
            border: `2px solid ${colors.primary}`,
            color: colors.primary,
          },
        },

        outlined: {
          color: alpha(colors.darkBlue, 0.75),
          backgroundColor: "#F7F7F7",
          boxShadow: "0px 8px 8px -4px rgba(73, 93, 207, 0.20)",

          border: "2px solid transparent",
          "&:hover": {
            backgroundColor: "white",
            border: `2px solid ${alpha(colors.darkBlue, 0.75)}`,
          },
        },
      },
    },
    MuiContainer: {
      defaultProps: {
        maxWidth: false,
        disableGutters: true,
      },

      styleOverrides: {
        root: {
          paddingInlineStart: "32px",
          paddingInlineEnd: "32px",

          "@media (min-width:1024px)": {
            paddingInlineStart: "64px",
            paddingInlineEnd: "64px",
          },

          "@media (min-width:1280px)": {
            paddingInlineStart: "0",
            paddingInlineEnd: "0",
          },
        },
      },
    },
    MuiStack: {
      defaultProps: {
        useFlexGap: true,
      },
    },
  },
  breakpoints: {
    values: {
      xs: 0,
      sm: 425,
      md: 768,
      lg: 1024,
      xl: 1280,
    },
  },
  spacing: 4
});
export default theme;
