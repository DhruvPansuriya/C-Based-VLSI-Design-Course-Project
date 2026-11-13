; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x334541 (bvmul arg0_6 arg1_2)))
(let ((?x327441 (bvmul (_ bv4294967295 32) ?x334541)))
(let ((?x479396 (bvmul arg0_6 arg1_8)))
(let ((?x289175 (bvadd ?x479396 ?x327441)))
(and (distinct ?x289175 (_ bv0 32)) true))))))
(check-sat)
