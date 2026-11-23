; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_52 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_38 () (_ BitVec 32))
(assert
 (let ((?x72905 (bvmul arg0_12 arg1_52)))
(let ((?x58878 (bvmul (_ bv4294967295 32) ?x72905)))
(let ((?x63555 (bvmul arg0_12 arg1_38)))
(let ((?x55742 (bvadd ?x63555 ?x58878)))
(and (distinct ?x55742 (_ bv0 32)) true))))))
(check-sat)
