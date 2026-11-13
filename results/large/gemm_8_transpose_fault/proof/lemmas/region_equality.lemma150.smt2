; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_42 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_21 () (_ BitVec 32))
(assert
 (let ((?x75214 (bvmul arg0_18 arg1_42)))
(let ((?x57564 (bvmul (_ bv4294967295 32) ?x75214)))
(let ((?x19954 (bvmul arg0_18 arg1_21)))
(let ((?x60359 (bvadd ?x19954 ?x57564)))
(and (distinct ?x60359 (_ bv0 32)) true))))))
(check-sat)
