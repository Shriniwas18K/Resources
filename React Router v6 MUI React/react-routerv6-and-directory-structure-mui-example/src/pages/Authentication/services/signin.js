import supabase from "../../../utils/supabase";

export const signin = async (req)=>{
    const {data,error}=await supabase.auth.signInWithPassword({
        email:req.email,
        password: req.password
    })
    window.localStorage
}