import supabase from "../../../utils/supabase";

export const signup = async (credentials) => {
    const { data, error } = await supabase.auth.signUp(credentials);
    alert('check your email')
}