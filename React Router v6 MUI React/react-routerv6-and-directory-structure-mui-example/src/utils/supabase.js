import { createClient } from '@supabase/supabase-js';

const VITE_SUPABASE_URL='https://xdzywseuegrhszxbukwl.supabase.co'
const VITE_SUPABASE_ANON_KEY='eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Inhkenl3c2V1ZWdyaHN6eGJ1a3dsIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MjY1ODk1MTcsImV4cCI6MjA0MjE2NTUxN30.TXNiRnGUxGSfnXFdrhQmV-PCJ6lwo-6m71G9s5vDuH0'
        
const supabaseUrl = VITE_SUPABASE_URL;
const supabaseKey = VITE_SUPABASE_ANON_KEY;
const supabase = createClient(supabaseUrl, supabaseKey);

export default supabase