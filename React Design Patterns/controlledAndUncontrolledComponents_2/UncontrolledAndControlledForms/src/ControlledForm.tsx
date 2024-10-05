// In Controlled Components , the state is maintained outside in above
// parent components , this is very useful for testing components
// In controlled Forms we can do runtime validation which increases
// user-experience , and prevents from submitting incorrect forms to
// server , such reducing server side load

//We have two way binding between state and form input elements
import { FC, useState, useEffect } from "react";
import { Form, FormData, SubmitButton, Input, ResetButton, Error } from "./FormStyles";
export const ControlledForm: FC = () => {
    const [name, setName] = useState<string>('');
    const [age, setAge] = useState<any>('');
    const [hairColor, setHairColor] = useState<string>('');
    const [formValidity, setFormValidity] = useState<boolean>(false);
    const [nameError, setNameError] = useState<string>('');
    const [ageError, setAgeError] = useState<string>('');
    const [hairColorError, setHairColorError] = useState<string>('');
    useEffect(() => {
        if (age < 0 || age > 120) {
            setAgeError('enter valid age between 0 to 120')
        } else{
            setAgeError('');
        }
        if (/^[a-zA-Z ]+$/.test(name) === false && name!='') {
            setNameError('name cannot contains numbers and special symbols')
        }else{
            setNameError('');
        }
         if (/^[a-zA-Z ]+$/.test(hairColor) === false && hairColor!='') {
            setHairColorError('hair color cannot contain numbers and special symbols')
        } else{
            setHairColorError('');
        }
        if (nameError || ageError || hairColorError) {
            setFormValidity(false);
        }
        else {
            setFormValidity(true);
        }
    }, [name, age, hairColor]);

    const resetForm = () => { setAge(''); setName(''); setHairColor(''); }
    const handleSubmit = () => {
        if (formValidity === true) {
            const formData: FormData = {
                name: name,
                age: parseInt(age, 10), // Parse age as a number
                hairColor: hairColor,
            };
            console.log(formData);
            resetForm();
        }
    }
    return (<>
        <Form onSubmit={handleSubmit}>
            <Input
                name="name"
                value={name}
                type="text"
                placeholder="Name"
                required
                onChange={e => setName(e.target!.value)}
            />
            <Error>{nameError}</Error>
            <Input
                name="age"
                type="number"
                value={age}
                required
                placeholder="Age"
                onChange={e => setAge(e.target!.value)} />
            <Error>{ageError}</Error>
            <Input
                name="hairColor"
                value={hairColor}
                type="text"
                placeholder="Blonde"
                required
                onChange={e => setHairColor(e.target!.value)} />
            <Error>{hairColorError}</Error>
            <SubmitButton type="submit" value="submit"/>
            {/* //submit is always of input element as we handle onSubmit event on its form tag */}
            <ResetButton onClick={resetForm}>clear</ResetButton>
            {/* //reset is always of button element as it is wants to jjust set state of form elements */}
            {/* //hence it can handle onClick event in form */}
        </Form>
    </>)
}
