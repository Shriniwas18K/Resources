import FacebookIcon from "./FacebookIcon";
import XIcon from "./XIcon";



const SocialMediaIcon = ({ name, sx }) => {
  let icon;

  switch (name) {
    case "facebook":
      icon = <FacebookIcon sx={sx} />;
      break;

    case "x":
      icon = <XIcon sx={sx} />;
      break;
  }
  return icon;
};

export default SocialMediaIcon;
